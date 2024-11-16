
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

class Graph {

    ArrayList<ArrayList<Integer>> arr = new ArrayList<>();
    int vertices;
    int edges;
    boolean[] vis = new boolean[200005];
    Queue<Integer> q = new LinkedList<>();
    int[] parent = new int[200005];
    boolean has_cycle = false;

    void init_vis() {
        Arrays.fill(vis, false);
    }

    void init_arraylist() {
        for (int i = 0; i < vertices; i++) {
            arr.add(new ArrayList<>());
        }
    }

    public Graph(int vertices, int edges) {
        this.vertices = vertices;
        this.edges = edges;
        init_arraylist();
        init_vis();
        Arrays.fill(parent, -1);

    }

    void DFS(int start) {
        vis[start] = true;
        System.out.print(start + " ");
        for (var i : arr.get(start)) {
            if (!vis[i]) {
                DFS(i);
            }
        }
    }

    void DFS_using_parent_array(int start) {

        System.out.print(start + " ");
        for (var i : arr.get(start)) {
            // System.out.print(i + " ");
            if (parent[i] == -1) {
                //System.out.print(i + " ");
                parent[i] = start;
                DFS_using_parent_array(i);
            }
        }
    }

    void DFS_using_parent(int start, int par) {

        System.out.print(start + " ");
        for (var i : arr.get(start)) {

            if (!(i == par)) {
                //System.out.print(i + " ");
                DFS_using_parent(i, start);
            }
        }
    }

    void DFS_iterative(int start) {
        Stack<Integer> st = new Stack<>();
        st.add(start);
        //System.out.print(start + " ");
        while (!st.isEmpty()) {
            int top = st.pop(); // Pop the top element

            if (!vis[top]) { // If not visited
                vis[top] = true; // Mark as visited
                System.out.print(top + " "); // Process the node (optional)

                // Add all neighbors to the stack
                for (int a : arr.get(top)) {
                    if (!vis[a]) {
                        st.add(a);
                    }
                }
            }
        }
    }

    void BFS(int start) {
        vis[start] = true;

        q.add(start);

        while (!q.isEmpty()) {
            int s = q.poll();
            for (var a : arr.get(s)) {
                if (!vis[a]) {
                    q.add(a);
                    vis[a] = true;
                }
            }
        }

    }

    // on the same path, the node has to be visited again -> cycle
    boolean path[] = new boolean[200005];

    boolean finding_cycle_directed_DFS(int start, int parent) {
        vis[start] = true;
        path[start] = true;
        for (var i : arr.get(start)) {
            if (!vis[i]) {
                if (finding_cycle_directed_DFS(i, start)) {
                    return true;
                }
                path[i] = true;
                vis[i] = true;
            } else if (path[i]) {
                return true;
            }
        }

        path[start] = false;
        return false;
    }

    boolean finding_cycle_undirected_BFS(int start) {
        //vis[start] = true;
        q.add(start);

        while (!q.isEmpty()) {
            int first = q.poll();
            if (vis[first]) {
                return true;
            }

            for (var it : arr.get(first)) {
                if (!vis[it]) {
                    q.add(it);
                    vis[it] = true;
                }
            }
        }
        return false;
    }

    boolean has_cycle_Directed_DFS(int start, int par) {

    }
}

public class BFS_DFS {

    public static void main(String[] args) {
        // Initialize the graph with 5 vertices and 6 edges
        int vertices = 5; // Number of vertices
        int edges = 6;    // Number of edges
        Graph graph = new Graph(vertices, edges);

        // Add edges to the adjacency list
        graph.arr.get(0).add(1);
        graph.arr.get(0).add(2);
        graph.arr.get(1).add(0);
        graph.arr.get(1).add(3);
        graph.arr.get(1).add(4);
        graph.arr.get(2).add(0);
        graph.arr.get(3).add(1);
        graph.arr.get(4).add(1);

        System.out.println("Graph Representation (Adjacency List):");
        for (int i = 0; i < vertices; i++) {
            System.out.println(i + " -> " + graph.arr.get(i));
        }

        // Test DFS (Recursive)
        System.out.println("\nDFS (Recursive) starting from node 0:");
        graph.init_vis(); // Reset visited array
        graph.DFS(0);

        // Test DFS Using Parent Array
        System.out.println("\n\nDFS Using Parent starting from node 0:");
        Arrays.fill(graph.parent, -1); // Reset parent array
        graph.DFS_using_parent(0, -1);

        System.out.println("\n\nDFS Using Parent Array starting from node 0:");
        Arrays.fill(graph.parent, -1); // Reset parent array
        graph.init_vis();
        graph.parent[0] = 0;
        graph.DFS_using_parent_array(0);

        // Test DFS Iterative
        System.out.println("\n\nDFS (Iterative) starting from node 0:");
        graph.init_vis(); // Reset visited array
        graph.DFS_iterative(0);

        // Test BFS
        System.out.println("\n\nBFS starting from node 0:");
        graph.init_vis(); // Reset visited array
        graph.BFS(0);
    }
}
