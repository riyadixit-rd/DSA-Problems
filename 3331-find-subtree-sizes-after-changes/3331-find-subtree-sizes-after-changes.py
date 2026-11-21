from typing import List

class Solution:
    def findSubtreeSizes(self, parent: List[int], s: str) -> List[int]:
        n = len(parent)
        adj = [[] for _ in range(n)]
        for i in range(1, n):
            adj[parent[i]].append(i)
            
        # Track the closest ancestor for each of the 26 lowercase letters
        last_seen = {}
        new_parent = list(parent)
        
        def dfs_find_parents(u: int):
            char = s[u]
            prev_ancestor = last_seen.get(char, -1)
            
            # If a matching ancestor exists, update u's parent
            if prev_ancestor != -1:
                new_parent[u] = prev_ancestor
                
            # Set u as the closest ancestor for s[u] for its descendants
            last_seen[char] = u
            
            for v in adj[u]:
                dfs_find_parents(v)
                
            # Backtrack: restore the previous ancestor state
            last_seen[char] = prev_ancestor

        dfs_find_parents(0)
        
        # Build the updated tree and calculate subtree sizes
        new_adj = [[] for _ in range(n)]
        for i in range(1, n):
            new_adj[new_parent[i]].append(i)
            
        ans = [1] * n
        def dfs_sizes(u: int) -> int:
            for v in new_adj[u]:
                ans[u] += dfs_sizes(v)
            return ans[u]
            
        dfs_sizes(0)
        return ans
