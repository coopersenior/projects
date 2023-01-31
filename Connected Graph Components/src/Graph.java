import java.util.HashSet;
import java.util.LinkedList;

public class Graph {
    private LinkedList<Integer>[] adjacencyList;
    private boolean[] visited;
    private int numEdges;
    private int startVertex;

    public Graph(int numVertices) {
        adjacencyList = new LinkedList[numVertices];
        startVertex = 0;
        visited = new boolean[numVertices];
        for (int i = 0; i < adjacencyList.length; i++) {
            adjacencyList[i] = new LinkedList<>();
        }
    }

    public int getNumVertices() {
        return adjacencyList.length;
    }

    public int getNumEdges() {
        return numEdges;
    }

    public void addEdge(int vertex1, int vertex2) {
        adjacencyList[vertex1].add(vertex2);
        adjacencyList[vertex2].add(vertex1);

        numEdges++;
    }

    public LinkedList<Integer> getNeighbors(int vertex) {
        return adjacencyList[vertex];
    }

    public void printConnectedComponents() {
        LinkedList<Integer> connected = new LinkedList<>();
        boolean first = true;
        boolean printed = false;
        for (int i = 0; i < getNumVertices(); i++) {
            if (connected.isEmpty()) {
                dfs(i, connected);
            }
            for (int k = 0; k < connected.size(); k++) {

                if (adjacencyList[i].size() > 0) {
                    if (!doesContain(adjacencyList[i], connected)) {
                        print(connected, first);
                        connected.clear();
                        first = false;
                        dfs(i, connected);
                        printed = true;
                    }
                }
            }
        }
        if (!printed) {
            print(connected, first);
        }
    }


    private boolean doesContain(LinkedList<Integer> adjacency, LinkedList<Integer> connected) {
        boolean doesContain = false;
        for (Integer k : connected) {
            if (adjacency.contains(k)) {
                doesContain = true;
            }
        }
        return doesContain;
    }

    private void dfs(int index, LinkedList<Integer> connected) {
        connected.add(index);
        visited[index] = true;
        for (int neighbor : getNeighbors(index)) {
            if (!visited[neighbor]) {
                dfs(neighbor, connected);
            }
        }
    }

    private void print(LinkedList<Integer> connected, boolean first) {
        if (!first) {
            System.out.print(",");
        }
        int length = connected.size();
        System.out.print("{");
        for (Integer k : connected) {
            System.out.print(k);
            if (length > 1) {
                System.out.print(",");
            }
            length--;
        }
        System.out.print("}");
    }
}