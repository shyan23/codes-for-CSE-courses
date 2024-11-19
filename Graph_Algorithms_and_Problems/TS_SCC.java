
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

class Graph {

    ArrayList<ArrayList<Integer>> arr = new ArrayList<>();
    int vertices;
    int edges;
    boolean[] vis;
    ArrayList<ArrayList<Integer>> rev_arr = new ArrayList<>();
    Stack<Integer> finishing_time = new Stack<>();
    ArrayList<ArrayList<Integer>> SCC_list = new ArrayList<>();
    ArrayList<ArrayList<Integer>> con_graph = new ArrayList<>();

    void init_vis() {
        Arrays.fill(vis, false);
    }

    void init_arraylist() {
        for (int i = 0; i <= vertices; i++) {
            arr.add(new ArrayList<>());
        }
    }

    void init_rev_arraylist() {
        for (int i = 0; i <= vertices; i++) {
            rev_arr.add(new ArrayList<>());
        }
    }

    void init_SCC_list_arraylist() {
        SCC_list.clear();
    }

    public Graph(int vertices, int edges) {
        this.vertices = vertices;
        this.edges = edges;
        vis = new boolean[vertices + 1]; // Dynamically allocate based on vertices
        init_arraylist();
        init_rev_arraylist();
    }

    void addEdge(int u, int v, ArrayList<ArrayList<Integer>> arr) {
        arr.get(u).add(v);
    }

    boolean finding_cycle_directed_DFS() {
        boolean[] path = new boolean[vertices + 1];
        init_vis();

        for (int i = 1; i <= vertices; i++) {
            if (!vis[i]) {
                if (finding_cycle_directed_DFS_util(i, path)) {
                    return true; // Cycle found
                }
            }
        }
        return false; // No cycle
    }

    boolean finding_cycle_directed_DFS_util(int start, boolean[] path) {
        vis[start] = true;
        path[start] = true;

        for (int i : arr.get(start)) {
            if (!vis[i]) {
                if (finding_cycle_directed_DFS_util(i, path)) {
                    return true; // Cycle found
                }
            } else if (path[i]) { // Node is in the current path -> Cycle detected
                return true;
            }
        }

        path[start] = false; // Backtrack
        return false;
    }

    void topological_sort_DFS() {
        if (finding_cycle_directed_DFS()) {
            System.out.println("The graph has cycles, topological sort cannot be done!");
            return;
        }

        Arrays.fill(vis, false); // Reset visited array for topological sort
        Stack<Integer> st = new Stack<>();

        for (int i = 1; i <= vertices; i++) {
            if (!vis[i]) {
                topological_sort_DFS_util(i, st);
            }
        }

        // Print the topological order
        System.out.println("Topological Sort:");
        while (!st.isEmpty()) {
            System.out.print(st.pop() + " ");
        }
        System.out.println();
    }

    void topological_sort_DFS_util(int start, Stack<Integer> st) {
        vis[start] = true;

        for (int i : arr.get(start)) {
            if (!vis[i]) {
                topological_sort_DFS_util(i, st);
            }
        }

        st.push(start); // Add the node to the stack after all its dependencies
    }

    void SCC() {
        init_vis();
        for (int i = 1; i <= vertices; i++) {
            if (!vis[i]) {
                SCC_util(i); // Perform DFS on the original graph
            }
        }

        Arrays.fill(vis, false); // Reset the visited array for the reverse graph
        while (!finishing_time.isEmpty()) {
            int a = finishing_time.pop(); // Pop from stack
            if (!vis[a]) {
                SCC_list.add(new ArrayList<>()); // Prepare a new SCC
                SCC_util_rev(a);
            }
        }
    }

    void SCC_util(int a) {
        vis[a] = true;
        for (int i : arr.get(a)) {
            if (!vis[i]) {
                SCC_util(i);
            }
        }
        finishing_time.add(a);
    }

    void SCC_util_rev(int a) {
        vis[a] = true;
        SCC_list.get(SCC_list.size() - 1).add(a); // Add node to the current SCC
        for (int i : rev_arr.get(a)) {
            if (!vis[i]) {
                SCC_util_rev(i);
            }
        }
    }

    void printSCCs() {
        System.out.println("SCCs in the graph:");
        for (int i = 0; i < SCC_list.size(); i++) {
            System.out.print("SCC " + (i + 1) + ": ");
            for (int node : SCC_list.get(i)) {
                System.out.print(node + " ");
            }
            System.out.println();
        }
    }

}

public class TS_SCC {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // User input for vertices and edges
        //System.out.println("Enter the number of vertices:");
        int vertices = sc.nextInt();

        //System.out.println("Enter the number of edges:");
        int edges = sc.nextInt();

        Graph g = new Graph(vertices, edges);

        // Take edge inputs
        //System.out.println("Enter the edges (format: u v for directed edge u -> v):");
        for (int i = 0; i < edges; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            g.addEdge(u, v, g.arr);
            g.addEdge(v, u, g.rev_arr);
        }

        // Perform SCC computation
        System.out.println("\nFinding Strongly Connected Components (SCCs):");
        g.SCC();
        g.printSCCs();

        sc.close();
    }
}
