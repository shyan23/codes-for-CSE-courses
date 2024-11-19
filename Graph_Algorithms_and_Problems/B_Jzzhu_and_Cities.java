
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

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
    //int[] dist = new int[10005];
    //ArrayList<int[]> dist_stack;

    public Graph(int vertices, int edges) {
        this.vertices = vertices;
        this.edges = edges;
        arr = new ArrayList<>(vertices + 1);
        //dist_stack = new ArrayList<>();

        // Initialize adjacency list for each vertex
        for (int i = 0; i <= vertices; i++) {
            arr.add(new ArrayList<>());
        }
    }

    void addEdge(int u, int v, int w) {
        arr.get(u).add(new Pair(v, w));
        arr.get(v).add(new Pair(u, w));
    }

    int[] dijkstra(int start,int n) {
        // Initialize distance array with the size of vertices + 1
        int[] dist = new int[n + 1];
        boolean[] vis = new boolean[n + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;

        PriorityQueue<Pair> pq = new PriorityQueue<>();
        pq.add(new Pair(start, 0));

        while (!pq.isEmpty()) {
            Pair p = pq.poll();
            int u = p.u;

            if (vis[u]) {
                continue;
            }
            vis[u] = true;

            for (Pair neighbor : arr.get(u)) {
                int v = neighbor.u; // destination
                int weight = neighbor.wt;   // weight to go to destination

                if (dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.add(new Pair(v, dist[v]));
                }
            }
        }

        return dist;
    }
}

public class B_Jzzhu_and_Cities {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, m, k;
        n = sc.nextInt();
        m = sc.nextInt();
        k = sc.nextInt();
        Graph g = new Graph(n, m);

        for (int i = 0; i < m; i++) {
            int x, y, z;
            x = sc.nextInt();
            y = sc.nextInt();
            z = sc.nextInt();

            g.arr.get(x).add(new Pair(y, z));
            g.arr.get(y).add(new Pair(x, z));

        }

        ArrayList<Pair> track = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            int u, v;
            u = sc.nextInt();
            v = sc.nextInt();

            track.add(new Pair(u, v));

            g.arr.get(1).add(new Pair(u, v));
            g.arr.get(u).add(new Pair(1, v));
        }

        int cnt = 0;
        int[] distance = g.dijkstra(1,n);

        for(int i = 1; i <=n;i++)
        {
            System.out.print(distance[i] + " ");
        }

    }
}
