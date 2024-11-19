
import java.util.*;

class Pair {

    int u;
    int v;

    public Pair(int u, int v) {
        this.u = u;
        this.v = v;
    }
}

class Edges implements Comparable<Edges> {

    int wt;
    Pair p;

    public Edges(int wt, Pair p) {
        this.wt = wt;
        this.p = p;
    }

    @Override
    public int compareTo(Edges ed) {
        return Integer.compare(this.wt, ed.wt);
    }
}

class DSU {

    int[] parent = new int[200004];
    int[] size = new int[200004];

    void make(int u) {
        parent[u] = u;
        size[u] = 1;
    }

    int find(int u) {
        if (u == parent[u]) {
            return u;
        } else {
            return parent[u] = find(parent[u]);
        }
    }

    void Union(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);

        if (root_a != root_b) {
            if (size[root_a] < size[root_b]) {
                int temp = root_a;
                root_a = root_b;
                root_b = temp;
            }
            parent[root_b] = root_a;
            size[root_a] += size[root_b];
        }
    }

    boolean make_cycle(int u, int v) {
        if (find(u) == find(v)) {
            return true;
        }
        Union(u, v);
        return false;
    }
}

class Graph {

    ArrayList<ArrayList<Pair>> arr = new ArrayList<>();
    PriorityQueue<Edges> pq = new PriorityQueue<>();
    ArrayList<ArrayList<Integer>> MST = new ArrayList<>();
    DSU d;
    int vertices;
    int edges;
    boolean[] vis = new boolean[200005];
    Queue<Integer> q = new LinkedList<>();
    int[] parent = new int[200005];

    void init_vis() {
        Arrays.fill(vis, false);
    }

    void init_arraylist() {
        for (int i = 0; i <= vertices; i++) {
            arr.add(new ArrayList<>());
        }
    }

    void init_MST() {
        for (int i = 0; i < 200005; i++) {
            MST.add(new ArrayList<>());
        }
    }

    public Graph(int vertices, int edges, DSU d) {
        this.vertices = vertices;
        this.edges = edges;
        init_arraylist();
        init_vis();
        init_MST();
        this.d = d;
        Arrays.fill(parent, -1);
    }

    void kruskal() {
        int cost = 0;
        while (!pq.isEmpty()) {
            Edges e = pq.poll();
            Pair p = e.p;
            int wt = e.wt;

            if (!d.make_cycle(p.u, p.v)) {
                cost += wt;
                MST.get(p.u).add(p.v);
                MST.get(p.v).add(p.u);
            }
        }
        System.out.println("Minimum Spanning Tree Cost: " + cost);
    }

    void minimum_path_using_kruskal(int start, int target) {
        init_vis();
        q.clear();
        Arrays.fill(parent, -1);

        q.add(start);
        vis[start] = true;

        while (!q.isEmpty()) {
            int curr = q.poll();

            for (int neighbor : MST.get(curr)) {
                if (!vis[neighbor]) {
                    vis[neighbor] = true;
                    parent[neighbor] = curr;
                    q.add(neighbor);

                    if (neighbor == target) {
                        ArrayList<Integer> path = new ArrayList<>();
                        int node = target;
                        while (node != -1) {
                            path.add(node);
                            node = parent[node];
                        }
                        System.out.print("Minimum Path: ");
                        for (int i = path.size() - 1; i >= 0; i--) {
                            System.out.print(path.get(i) + (i > 0 ? " -> " : "\n"));
                        }
                        return;
                    }
                }
            }
        }

        System.out.println("No path exists between " + start + " and " + target);
    }

    void Prim(int start) {
        boolean[] vis = new boolean[vertices + 1]; // Dynamic visited array
        PriorityQueue<Pair> p = new PriorityQueue<>((a, b) -> Integer.compare(a.v, b.v)); // Min-heap based on weight
        int sum = 0;
    
        // Add the starting node to the priority queue
        p.add(new Pair(start, 0));
        ArrayList<Pair> mstEdges = new ArrayList<>(); // Store MST edges
    
        while (!p.isEmpty()) {
            Pair curr = p.poll();
            int node = curr.u;
            int wt = curr.v;
    
            // If the node is already visited, skip it
            if (vis[node]) continue;
    
            // Mark the node as visited
            vis[node] = true;
    
            // Add the weight to the MST sum
            sum += wt;
    
            // Collect the MST edge
            if (wt != 0) { // Ignore the starting node edge
                mstEdges.add(curr);
            }
    
            // Traverse all adjacent edges
            for (Pair neighbor : arr.get(node)) {
                if (!vis[neighbor.u]) {
                    p.add(neighbor);
                }
            }
        }
    
        // Output the results
        System.out.println("Total weight of MST: " + sum);
        System.out.println("Edges in the MST:");
        for (Pair edge : mstEdges) {
            System.out.println("Edge: " + edge.u + " with weight: " + edge.v);
        }
    }
    
     
    }

    public class Kruskal_Prim {

        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            DSU d = new DSU();
            int v, e;
            v = sc.nextInt();
            e = sc.nextInt();

            for (int i = 1; i <= v; i++) {
                d.make(i);
            }

            Graph g = new Graph(v, e, d);

            for (int i = 0; i < e; i++) {
                int a, b, wt;
                a = sc.nextInt();
                b = sc.nextInt();
                wt = sc.nextInt();

                Pair p = new Pair(a, b);
                g.pq.add(new Edges(wt, p));
                g.arr.get(a).add(new Pair(b, wt));
                g.arr.get(b).add(new Pair(a, wt));
            }

            g.kruskal();

            int start = sc.nextInt();
            int target = sc.nextInt();
            g.minimum_path_using_kruskal(start, target);
            System.out.println();

            g.Prim(1);

        }
    }
