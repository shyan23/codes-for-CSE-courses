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
    int vertices;
    int edges;

    public Graph(int vertices, int edges) {
        this.vertices = vertices;
        this.edges = edges;
        arr = new ArrayList<>(vertices + 1);

        // Initialize adjacency list for each vertex
        for (int i = 0; i <= vertices; i++) {
            arr.add(new ArrayList<>());
        }
    }

    void addEdge(int u, int v, int w) {
        arr.get(u).add(new Pair(v, w)); // Directed edge from u to v with weight w
    }

    void dijkstra(int start) 
    {
        // Initialize distance array with the size of vertices + 1
        int[] dist = new int[vertices + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;

        PriorityQueue<Pair> pq = new PriorityQueue<>();
        pq.add(new Pair(start, 0));

        while (!pq.isEmpty()) {
            Pair p = pq.poll();
            int u = p.u;
            int distance = p.wt;

            if (distance > dist[u]) continue;

            for (Pair neighbor : arr.get(u)) {
                int v = neighbor.u; // destination
                int weight = neighbor.wt;   // weight to go to destination

                if (  dist[u] + weight < dist[v]) {   
                    dist[v] = dist[u] + weight; 
                    pq.add(new Pair(v, dist[v]));
                }
            }
        }

        // Output distances for each vertex
        for(int i = 1; i <= vertices; i++) {
            System.out.print((dist[i] == Integer.MAX_VALUE ? -1 : dist[i]) + " ");
        }
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int v = sc.nextInt();
        int e = sc.nextInt();
        
        Graph g = new Graph(v, e);

        for (int i = 0; i < e; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            int z = sc.nextInt();
            g.addEdge(x, y, z); // Directed edge
        }

        g.dijkstra(1);
    }
}
