/*
  总面积 - 交叉面积

Find the total area covered by two rectilinear rectangles in a 2D plane.

 */

class Solution:
    # @param {integer} A
    # @param {integer} B
    # @param {integer} C
    # @param {integer} D
    # @param {integer} E
    # @param {integer} F
    # @param {integer} G
    # @param {integer} H
    # @return {integer}
    def computeArea(self, A, B, C, D, E, F, G, H):
        sums = (C - A) * (D - B) + (G - E) * (H - F)
        return sums - max(min(C, G) - max(A, E), 0) * max(min(D, H) - max(B, F), 0)
