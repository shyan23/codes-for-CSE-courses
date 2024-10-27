import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;


// TODO : Correct the pathFinder function



class Graph {
    String filename;
    int vertices;
    int edges;
    boolean[] marked;
    ArrayList<ArrayList<Integer>> adj_list = new ArrayList<>();
    Queue<Integer> queue;
    int[] edge_To;
    Stack<Integer> path_list;

    public Graph(String filename) {
        this.filename = filename;
        initialize();
    }

    void initialize() {
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            // Read the first line to get the number of vertices and edges
            String firstLine = br.readLine();
            if (firstLine != null) {
                String[] parts = firstLine.split(" ");
                vertices = Integer.parseInt(parts[0]); 
                edges = Integer.parseInt(parts[1]);
            }

            // Initialize data structures based on the number of vertices
            initialize_arraylist();
            initialize_marked();

            // Read each edge and add it to the adjacency list
            for (int i = 0; i < edges; i++) {
                String line = br.readLine();
                if (line != null) {
                    String[] parts = line.split(" ");
                    int x = Integer.parseInt(parts[0]) - 1; // Adjusting for 0-based indexing
                    int y = Integer.parseInt(parts[1]) - 1; // Adjusting for 0-based indexing

                    add_edge(x, y);
                }
            }
        } catch (IOException e) {
            System.err.println("Error: File not found or unable to read.");
        }
    }

    void initialize_arraylist() {
        for (int i = 0; i < vertices; i++) {
            adj_list.add(new ArrayList<>());
        }
    }

    void initialize_marked() {
        marked = new boolean[vertices];
    }

    void initialize_edge_to() {
        edge_To = new int[vertices];
    }

    void initialize_stack() {
        path_list = new Stack<>();
    }

    void initialize_Queue() {
        queue = new LinkedList<>();
    }

    void add_edge(int x, int y) {
        if (x >= vertices || y >= vertices) {
            System.out.println("Error: Vertex out of bounds.");
            return;
        }
        adj_list.get(x).add(y);
        adj_list.get(y).add(x);
    }

    void BFS(int vertex) {
        if (vertex >= vertices) {
            System.out.println("Error: Vertex out of bounds.");
            return;
        }
        initialize_marked();
        initialize_Queue();
        BFS_util(vertex);
    }

    void BFS_util(int vertex) {
        marked[vertex] = true;
        queue.add(vertex);

        while (!queue.isEmpty()) {
            int mem = queue.poll();
            System.out.print(mem + 1 + " "); // Adjusting for 1-based output

            for (var i : adj_list.get(mem)) {
                if (!marked[i]) {
                    marked[i] = true;
                    queue.add(i);
                }
            }
        }
        System.out.println();
    }

    void DFS(int vertex) {
        if (vertex >= vertices) {
            System.out.println("Error: Vertex out of bounds.");
            return;
        }
        initialize_marked();
        DFS_util(vertex);
        System.out.println();
    }

    void DFS_util(int vertex) {
        marked[vertex] = true;
        System.out.print(vertex + 1 + " "); // Adjusting for 1-based output

        for (var child : adj_list.get(vertex)) {
            if (!marked[child]) {
                DFS_util(child);
            }
        }
    }

    public boolean has_path(int s, int v) {
        if (s >= vertices || v >= vertices) {
            System.out.println("Error: Vertex out of bounds.");
            return false;
        }
        initialize_marked();
        return has_path_util(s, v);
    }

    boolean has_path_util(int s, int v) {
        marked[s] = true;
        if (s == v) return true;
        for (var child : adj_list.get(s)) {
            if (!marked[child]) {
                if (has_path_util(child, v)) return true;
            }
        }
        return false;
    }

    void path(int s, int v) {
        if (s >= vertices || v >= vertices) {
            System.out.println("Error: Vertex out of bounds.");
            return;
        }

        if (has_path(s, v)) {
            initialize_marked();
            initialize_stack();
            path_list.push(s);
            path_finder_util(s, v);

            if (path_list.peek() == v) {
                Stack<Integer> reversedPath = new Stack<>();
                while (!path_list.isEmpty()) {
                    reversedPath.push(path_list.pop());
                }
                while (!reversedPath.isEmpty()) {
                    System.out.print((reversedPath.pop() + 1) + " "); // Adjusting for 1-based output
                }
                System.out.println();
            } else {
                System.out.println("No path found from " + (s + 1) + " to " + (v + 1));
            }
        }
    }

    void path_finder_util(int s, int v) {
        marked[s] = true;
        if (s == v) return;

        for (var i : adj_list.get(s)) {
            if (!marked[i]) {
                path_list.push(i);
                path_finder_util(i, v);
                if (path_list.peek() == v) return;
                path_list.pop();
            }
        }
    }

    void print_adjlist() {
        for (int i = 0; i < vertices; i++) {
            System.out.print((i + 1) + ": "); // Adjusting for 1-based output
            for (var j : adj_list.get(i)) {
                System.out.print((j + 1) + " "); // Adjusting for 1-based output
            }
            System.out.println();
        }
    }
}

class CC 
{
    Graph g;
    int count ;

    boolean isConnected(int s, int v)
    {
        
        return false;
    }
    CC(Graph g)
    {
        this.g = g;
    }
}







public class Eval {
    public static void main(String[] args) {
        Graph G = new Graph("input.txt");

        System.out.println("Adjacency List:");
        G.print_adjlist();

        System.out.println("\nBFS Traversal from vertex 1:");
        G.BFS(0);

        System.out.println("\nDFS Traversal from vertex 1:");
        G.DFS(0);


    }
}
