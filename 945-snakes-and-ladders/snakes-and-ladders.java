class Solution {
    public int snakesAndLadders(int[][] board) {
        int n = board.length;
        boolean[] visited = new boolean[n * n + 1];
        Queue<int[]> queue = new LinkedList<>(); // {cell, moves}
        queue.offer(new int[]{1, 0});
        visited[1] = true;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int pos = current[0];
            int moves = current[1];

            for (int i = 1; i <= 6 && pos + i <= n * n; i++) {
                int next = pos + i;
                int[] rc = getCoordinates(next, n);
                if (board[rc[0]][rc[1]] != -1) {
                    next = board[rc[0]][rc[1]];
                }

                if (next == n * n) {
                    return moves + 1;
                }

                if (!visited[next]) {
                    visited[next] = true;
                    queue.offer(new int[]{next, moves + 1});
                }
            }
        }

        return -1;
    }

    private int[] getCoordinates(int num, int n) {
        int r = n - 1 - (num - 1) / n;
        int c = (num - 1) % n;
        if ((n - r) % 2 == 0) {
            c = n - 1 - c;
        }
        return new int[]{r, c};
    }
}
