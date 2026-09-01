from collections import deque

class Solution:
    def minMoves(self, classroom, energy):
        m = len(classroom)
        n = len(classroom[0])

        # Give every litter a bit number
        litter_id = {}
        start_r = start_c = 0
        k = 0

        for i in range(m):
            for j in range(n):
                if classroom[i][j] == 'S':
                    start_r, start_c = i, j
                elif classroom[i][j] == 'L':
                    litter_id[(i, j)] = k
                    k += 1

        # No litter at all
        if k == 0:
            return 0

        full_mask = (1 << k) - 1

        # BFS:
        # (row, col, remaining_energy, collected_mask)
        q = deque()
        q.append((start_r, start_c, energy, 0))

        # best[r][c][mask] = maximum energy with which
        # we have reached this state
        best = [[[-1] * (1 << k) for _ in range(n)] for _ in range(m)]
        best[start_r][start_c][0] = energy

        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        moves = 0

        while q:
            size = len(q)

            for _ in range(size):
                r, c, e, mask = q.popleft()

                for dr, dc in directions:
                    nr = r + dr
                    nc = c + dc

                    # Outside grid
                    if nr < 0 or nr >= m or nc < 0 or nc >= n:
                        continue

                    # Obstacle
                    if classroom[nr][nc] == 'X':
                        continue

                    # Need 1 energy for every move
                    if e == 0:
                        continue

                    ne = e - 1
                    nmask = mask

                    # Collect litter
                    if classroom[nr][nc] == 'L':
                        bit = litter_id[(nr, nc)]
                        nmask |= (1 << bit)

                    # Reset energy
                    if classroom[nr][nc] == 'R':
                        ne = energy

                    # All litter collected
                    if nmask == full_mask:
                        return moves + 1

                    # If energy becomes 0, we can only continue
                    # if we are standing on R.
                    if ne == 0 and classroom[nr][nc] != 'R':
                        continue

                    # If we have already reached this exact
                    # position + mask with >= energy, this state
                    # cannot give us anything better.
                    if best[nr][nc][nmask] >= ne:
                        continue

                    best[nr][nc][nmask] = ne
                    q.append((nr, nc, ne, nmask))

            moves += 1

        return -1