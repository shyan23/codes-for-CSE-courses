import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class EVALUATION_ {
    static ArrayList<ArrayList<Integer>> adj_list = new ArrayList<>();
    static ArrayList<ArrayList<Integer>> rev_adj_list = new ArrayList<>();
    static ArrayList<ArrayList<Integer>> Components = new ArrayList<>();
    static int vertices;
    static int edges;
    static boolean[] vis;
    static Stack<Integer> st = new Stack<>();
    static int[] indegree;
    static ArrayList<Integer> Component = new ArrayList<>();
    static int NumComponents;
    static Queue<Integer>queue;

    static void init_queue()
    {
        queue = new LinkedList<>();
    }

    static void print_list(ArrayList<Integer>arr)
    {
        for(var i : arr)
        {
            System.out.print(i + " ");
        }
        System.out.println();
    }
    static void print_listlist(ArrayList<ArrayList<Integer>>arr)
    {
        for(var i : arr)
        {
            for (var j : i){
                System.out.print(j + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    static void init_Components(int n) {
        Components.clear();  // Clear Components list before initialization
        for (int i = 0; i < n; i++) {
            Components.add(new ArrayList<>());
        }
    }

    static void init_adj_list(int n) {
        adj_list.clear();  // Clear adj_list before initialization
        for (int i = 0; i < n; i++) {
            adj_list.add(new ArrayList<>());
        }
    }

    static void init_rev_adj_list(int n) {
        rev_adj_list.clear();  // Clear rev_adj_list before initialization
        for (int i = 0; i < n; i++) {
            rev_adj_list.add(new ArrayList<>());
        }
    }

    static void init_vis(int n) {
        vis = new boolean[n];
    }

    static void Topological_Sort() {
        init_vis(vertices);
        for (int i = 0; i < vertices; i++) {
            if (!vis[i]) {
                Topological_SortDFS_Util(i);
            }
        }
        while (!st.empty()) {
            System.out.print(st.pop() + " ");
        }
        System.out.println();
    }

    static void Topological_SortDFS_Util(int vertex) {
        vis[vertex] = true;
        for (int i : adj_list.get(vertex)) {
            if (!vis[i]) {
                Topological_SortDFS_Util(vertex);
            }
        }
        st.add(vertex);
    }

    static void allTopologicalSorts() {
        indegree = new int[vertices];
        init_vis(vertices);

        // Initialize indegrees of all vertices
        for (int i = 0; i < vertices; i++) {
            for (var neighbor : adj_list.get(i)) {
                indegree[neighbor]++;
            }
        }

        ArrayList<Integer> stack = new ArrayList<>();
        allTopologicalSortsUtil(stack);
    }

    static void allTopologicalSortsUtil(ArrayList<Integer> stack) {
        boolean flag = false;

        for (int i = 0; i < vertices; i++) {
            if (!vis[i] && indegree[i] == 0) {
                vis[i] = true;
                stack.add(i);

                // Reduce indegree of adjacent vertices
                for (var adj : adj_list.get(i)) {
                    indegree[adj]--;
                }

                allTopologicalSortsUtil(stack);

                // Backtrack
                vis[i] = false;
                stack.remove(stack.size() - 1);
                for (var adj : adj_list.get(i)) {
                    indegree[adj]++;
                }

                flag = true;
            }
        }

        // If flag is false, all vertices are included in the topological sort
        if (!flag) {
            stack.forEach(i -> System.out.print(i + " "));
            System.out.println();
        }
    }

    static void SCC() {
        init_Components(vertices);  // Initialize Components for each vertex
        for (int i = 0; i < vertices; i++) {
            if (!vis[i]) SCCUtil_1(i);
        }

        init_vis(vertices);

        System.out.println("Strongly Connected Components:");
        while (!st.empty()) {
            int vertex = st.pop();

            if (!vis[vertex]) {
                System.out.print("Component " + (NumComponents + 1) + ": ");
                SCCUtil_2(vertex);
                NumComponents++;
                System.out.println();
            }
        }
    }

    static void SCCUtil_1(int vertex) {
        vis[vertex] = true;

        for (var i : adj_list.get(vertex)) {
            if (!vis[i]) {
                SCCUtil_1(i);
            }
        }
        st.push(vertex);  // Push after all adjacent vertices are processed
    }

    static void SCCUtil_2(int vertex) {
        System.out.print(vertex + " ");
        vis[vertex] = true;
        Components.get(NumComponents).add(vertex);

        for (var i : rev_adj_list.get(vertex)) {
            if (!vis[i]) {
                SCCUtil_2(i);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        vertices = sc.nextInt();
        edges = sc.nextInt();
        NumComponents = 0;  // Reset component count

        init_adj_list(vertices);
        init_rev_adj_list(vertices);
        init_vis(vertices);  // Initialize vis array here before SCC
        init_Components(vertices);

        // Reading edges of the graph
        for (int i = 0; i < edges; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            adj_list.get(x).add(y);
            rev_adj_list.get(y).add(x);
        }

        // Run SCC to find all Strongly Connected Components
        SCC();
        System.out.println("Total number of Strongely Connected Componets: " + NumComponents);
        System.out.println();
        print_listlist(Components);


        // Uncomment to print topological sorts if needed
        // System.out.println("Single Topological Sort:");
        // Topological_Sort();

        // System.out.println("All Topological Sorts:");
        // allTopologicalSorts();
    }
}
