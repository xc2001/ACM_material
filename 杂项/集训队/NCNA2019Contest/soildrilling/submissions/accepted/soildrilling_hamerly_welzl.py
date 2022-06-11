#!/usr/bin/env python3

from __future__ import division

import fractions
import math
import random
import sys

# Recursive implementation of Welzl's linear-time randomized algorithm for
# finding the smallest circle enclosing a set of points.

# This version can be exact if the following flag is set to True; if so, then
# until the last sqrt the answer is kept as a rational. This is about 10x
# slower.
USE_EXACT_ALGORITHM = False
NUMBER_TYPE = fractions.Fraction if USE_EXACT_ALGORITHM else float

sys.setrecursionlimit(10000)
random.seed(42) # make our randomized algorithm have deterministic behavior

class Point(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def norm2(self): return self.x * self.x + self.y * self.y
    def __sub__(self, other): return Point(self.x - other.x, self.y - other.y)
    def __add__(self, other): return Point(self.x + other.x, self.y + other.y)
    def __mul__(self, other): return Point(self.x * other, self.y * other)
    def __truediv__(self, other): return Point(self.x / other, self.y / other)
    def __hash__(self): return hash((self.x, self.y))
    def __eq__(self, other): return (self.x, self.y) == (other.x, other.y)
    def __repr__(self): return '({}, {})'.format(self.x, self.y)

# three distinct points define a circle
#   a, b, c
#
#   <a-p,a-p> - r^2 = 0 (1)
#   <b-p,b-p> - r^2 = 0 (2)
#   <c-p,c-p> - r^2 = 0 (3)
#
#   Taking (2) - (1) eliminates terms leading to:
#       <b,b> - <a,a> - 2<p,b-a> = 0
#   Taking (3) - (1) eliminates terms leading to:
#       <c,c> - <a,a> - 2<p,c-a> = 0
#   
#   Solving each of these for p.x and setting them equal to each other gives
#       <b,b> - <a,a> - 2p.y(b.y-a.y)   <c,c> - <a,a> - 2p.y(c.y-a.y)
#       ----------------------------- = -----------------------------
#             2(b.x-a.x)                      2(c.x-a.x)
#
#   Let B = <b,b> - <a,a>               C = <c,c> - <a,a>
#       D = 2(b.y-a.y)                  E = 2(c.y-a.y)
#       F = 2(b.x-a.x)                  G = 2(c.x-a.x)
#   
#   Gives (B - p.y * D) / F = (C - p.y * E) / G
#
#   and p.y = (F*C - G*B) / (F*E - G*D)
#
#   Then plug in p.y to get p.x, and then both to get r^2

class Circle(object):
    def __init__(self, c, r2):
        self.c = c
        self.r2 = r2

    def contains(self, p):
        return (p - self.c).norm2() <= self.r2

    def __repr__(self):
        return '({}, {})'.format(self.c, self.r2)

    @staticmethod
    def from_points(*points):
        if not points:
            return Circle(Point(0, 0), 0)
        if len(points) == 1:
            return Circle(points[0], 0)
        if len(points) == 2:
            return Circle.from_two_points(*points)
        if len(points) == 3:
            return Circle.from_three_points(*points)
        assert False, points

    @staticmethod
    def from_two_points(*points):
        c = (points[0] + points[1]) / 2
        r2 = (points[0] - c).norm2()
        return Circle(c, r2)

    @staticmethod
    def from_three_points(a, b, c):
        B = b.norm2() - a.norm2()
        D = 2 * (b.y - a.y)
        F = 2 * (b.x - a.x)

        C = c.norm2() - a.norm2()
        E = 2 * (c.y - a.y)
        G = 2 * (c.x - a.x)

        denom = F * E - G * D
        if denom == 0:
            # a, b, c are collinear (but distinct); take the two extreme points
            # and form a circle
            ab = (a - b).norm2()
            ac = (a - c).norm2()
            bc = (b - c).norm2()
            _, p0, p1 = max((ab, a, b), (ac, a, c), (bc, b, c))
            return Circle.from_two_points(p0, p1)
        num = F * C - G * B

        # now we have the center (px, py)
        py = num / denom
        px = (B - py * D) / F if F else (C - py * E) / G
        p = Point(px, py)
        # and the radius^2
        ap = p - a
        r2 = ap.norm2()

        return Circle(p, r2)

# according to Welzl's paper on the SED (smallest enclosing disk),
# https://inf.ethz.ch/personal/emo/PublFiles/SmallEnclDisk_LNCS555_91.pdf
def sed_welzl(P, R):
    '''Find the smallest enclosing disk using interior points P and boundary
    points R, where |R| <= 3 (because no more than 3 points are needed to
    define a circle).'''

    if (not P) or len(R) == 3:
        # base case: there are no interior points, or we have enough boundary
        # points to form a circle
        return Circle.from_points(*R)

    # choose a point at random and remove it
    i = random.randint(0, len(P)-1)
    P[i], P[-1] = P[-1], P[i]
    p = P.pop()

    # try to form a circle without this point
    D = sed_welzl(P, R)

    # In Welzl's original algorithm, there could be an "empty" disk; we don't
    # have that (we just use a circle at the origin), so we don't test whether
    # D "exists"
    if not D.contains(p):
        # if the circle formed doesn't contain p, then p needs to be on the
        # boundary; add it to R and recurse
        R.append(p)
        D = sed_welzl(P, R)
        R.pop()

    # replace the point that was removed earlier (not at the same location, but
    # it doesn't matter)
    P.append(p)

    return D


def main():
    n = int(sys.stdin.readline())
    points = [tuple(map(NUMBER_TYPE, sys.stdin.readline().split())) for _ in range(n)]

    xy = list({Point(x, y) for x, y, z in points})
    xz = list({Point(x, z) for x, y, z in points})
    yz = list({Point(y, z) for x, y, z in points})

    smallest = 1e100
    for pts in [xy, xz, yz]:
        c = sed_welzl(pts, [])
        smallest = min(smallest, c.r2)

    print('{:.10f}'.format(math.sqrt(smallest) * 2))

if __name__ == '__main__':
    main()

