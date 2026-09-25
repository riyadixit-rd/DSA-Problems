class Solution {
    int i = 0;

    public List<String> braceExpansionII(String expression) {
        List<String> ans = new ArrayList<>(parse(expression));
        Collections.sort(ans);
        return ans;
    }

    Set<String> parse(String s) {
        Set<String> res = new HashSet<>();
        res.add("");

        while (i < s.length() && s.charAt(i) != '}') {
            char c = s.charAt(i);

            if (c == ',') {
                i++;
                res.addAll(parse(s));
            } else {
                Set<String> next;

                if (c == '{') {
                    i++;
                    next = parse(s);
                    i++;
                } else {
                    next = new HashSet<>();
                    next.add(String.valueOf(c));
                    i++;
                }

                Set<String> temp = new HashSet<>();

                for (String a : res) {
                    for (String b : next) {
                        temp.add(a + b);
                    }
                }

                res = temp;
            }
        }

        return res;
    }
}