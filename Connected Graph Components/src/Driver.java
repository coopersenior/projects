import java.util.LinkedList;

public class Driver {

    public static void main(String[] args) {
/*
        Graph graph = new Graph(10);
        graph.addEdge(0,1);
        graph.addEdge(0,2);
        graph.addEdge(2,1);
        graph.addEdge(1,3);
        graph.addEdge(2,4);
        graph.addEdge(3,5);
        graph.addEdge(4,5);
*/
        Graph graph = new Graph(10);
        graph.addEdge(1,0);
        graph.addEdge(1,3);
        graph.addEdge(0,3);
        graph.addEdge(0,2);
        graph.addEdge(2,4);
        graph.addEdge(3,4);

        graph.addEdge(5,6);
        graph.addEdge(6,8);
        graph.addEdge(7,7);



        graph.printConnectedComponents();
    }
}
