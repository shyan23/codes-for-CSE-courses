import java.util.*;
import java.io.*;

public class ShortestRoutes {
    
    static class Edge {
        int destination;
        long weight;

        Edge(int destination, long weight) {
            this.destination = destination;
            this.weight = weight;
        }
    }

    static class Node implements Comparable<Node> {
        int id;
        long distance;

        Node(int id, long distance) {
            this.id = id;
            this.distance = distance;
        }

        @Override
        public int compareTo(Node other) {
            return Long.compare(this.distance, other.distance);
        }
    }

    public static void main(String[] args) throws IOException {
        // Input handling
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] firstLine = br.readLine().split(" ");
        int n = Integer.parseInt(firstLine[0]);
        int m = Integer.parseInt(firstLine[1]);

        // Graph representation
        List<List<Edge>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        // Read edges
        for (int i = 0; i < m; i++) {
            String[] edgeData = br.readLine().split(" ");
            int u = Integer.parseInt(edgeData[0]) - 1; // zero-indexed for Java array use
            int v = Integer.parseInt(edgeData[1]) - 1;
            long weight = Long.parseLong(edgeData[2]);
            graph.get(u).add(new Edge(v, weight));
        }

        // Dijkstra’s algorithm from city 1 (index 0)
        long[] distances = dijkstra(n, graph, 0);

        // Output results
        StringBuilder output = new StringBuilder();
        for (long distance : distances) {
            output.append(distance == Long.MAX_VALUE ? -1 : distance).append(" ");
        }
        System.out.println(output.toString().trim());
    }

    private static long[] dijkstra(int n, List<List<Edge>> graph, int start) {
        long[] distances = new long[n];
        Arrays.fill(distances, Long.MAX_VALUE);
        distances[start] = 0;

        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(start, 0));

        while (!pq.isEmpty()) {
            Node currentNode = pq.poll();
            int u = currentNode.id;
            long currentDist = currentNode.distance;

            if (currentDist > distances[u]) continue;

            // Explore neighbors
            for (Edge edge : graph.get(u)) {
                int v = edge.destination;
                long weight = edge.weight;

                if (distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                    pq.add(new Node(v, distances[v]));
                }
            }
        }
        return distances;
    }
}
