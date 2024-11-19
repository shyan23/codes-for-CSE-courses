import java.util.*;

class Pair implements Comparable<Pair> {

    int u, wt;

    public Pair(int u, int wt) {
        this.u = u;
        this.wt = wt;
    }

    @Override
    public int compareTo(Pair t) {
        return Integer.compare(this.wt, t.wt);
    }
}

class Graph {

    ArrayList<ArrayList<Pair>> arr;
    int[] parent;
    int vertices;
    int edges;
    int[] dist;
    boolean[] vis;

    public Graph(int vertices, int edges) {
        this.vertices = vertices;
        this.edges = edges;

        // Initialize adjacency list and other arrays
        arr = new ArrayList<>(vertices + 1);
        parent = new int[vertices + 1];
        dist = new int[vertices + 1];
        vis = new boolean[vertices + 1];
        Arrays.fill(parent, -1);

        for (int i = 0; i <= vertices; i++) {
            arr.add(new ArrayList<>());
        }
    }

    void addEdge(int u, int v, int w) {
        arr.get(u).add(new Pair(v, w));
        arr.get(v).add(new Pair(u, w));
    }

    void dijkstra(int start, int end) {
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;

        PriorityQueue<Pair> pq = new PriorityQueue<>();
        pq.add(new Pair(start, 0));

        while (!pq.isEmpty()) {
            Pair p = pq.poll();
            int u = p.u;

            if (u == end) {
                return; // Early exit if the target is reached
            }

            if (vis[u]) {
                continue;
            }
            vis[u] = true;

            for (Pair neighbor : arr.get(u)) {
                int v = neighbor.u;
                int weight = neighbor.wt;

                if (dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.add(new Pair(v, dist[v]));
                    parent[v] = u;
                }
            }
        }
    }

    void getPath(int end) {
        if (dist[end] == Integer.MAX_VALUE) {
            System.out.println("-1"); // No path exists
            return;
        }

        ArrayList<Integer> path = new ArrayList<>();
        for (int i = end; i != -1; i = parent[i]) {
            path.add(i); // Reconstruct path
        }

        Collections.reverse(path); // Reverse the path to start from source

        for (int node : path) {
            System.out.print(node + " ");
        }
        System.out.println();
    }
}

public class C_Dijkstra {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int v = sc.nextInt(); // Number of vertices
        int e = sc.nextInt(); // Number of edges

        Graph g = new Graph(v, e);

        for (int i = 0; i < e; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            int z = sc.nextInt();
            g.addEdge(x, y, z);
        }

        g.dijkstra(1, v); // Find shortest path from node 1 to node v
        g.getPath(v); // Print the path

        sc.close();
    }
}
