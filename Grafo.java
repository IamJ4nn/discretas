import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class Grafo {

    List<List<Integer>> lista_grafo;
    boolean visitados[];
    int nodos;

    Grafo(int nodos) {

        this.lista_grafo = new ArrayList<>();
        visitados = new boolean[nodos];
        this.nodos = nodos;

        for (int i = 0; i < nodos; i++) {
            lista_grafo.add(i, new ArrayList<>());
        }

    }

    public void añadirArista(int a, int b) {

        // Función List.get() : Returns the element at the specified position in this
        // list.

        lista_grafo.get(a).add(b); // ingresa el nodo (a), junto con el otro nodo que tiene conexión (b)
        lista_grafo.get(b).add(a);// al ser un grafo no dirigido se replica inversamente

    }

    public boolean grafoConectado() {

        int indiceInicio = 0;
        dfs(indiceInicio);

        for (int i = 0; i < visitados.length; i++) {
            if (visitados[i] == false) {
                System.out.println("Compuesto");
                return false;
            }
        }

        System.out.println("Sustancia pura");
        return true;
    }

    public void dfs(int inicio) {

        Stack<Integer> pila = new Stack<>(); // crea una pila
        pila.push(inicio); // ingresa el nodo por el cual quiere empezar la busquedad
        visitados[inicio] = true; // arreglo booleano auxiliar en la posición del valor ingresado, lo ve como
                                  // verdadero

        while (!pila.isEmpty()) {
            Integer nodo = pila.pop();

            List<Integer> vecinos = lista_grafo.get(nodo);

            for (Integer vecino : vecinos) {
                if (!visitados[vecino]) {
                    pila.push(vecino);
                    visitados[vecino] = true;
                }
            }

        }
    }

    public static boolean tipoDeSustancia(int nodos, int aristas) {

        int a, b;
        Scanner s = new Scanner(System.in);

        Grafo grafo_prueba = new Grafo(nodos);

        for (int i = 0; i < aristas; i++) {
            a = s.nextInt();
            b = s.nextInt();
            grafo_prueba.añadirArista(a, b);
        }

        return grafo_prueba.grafoConectado();

    }

    public static void main(String[] args) {

        int n, nodos, aristas;

        Scanner s = new Scanner(System.in);
        n = s.nextInt();

        for (int i = 0; i < n; i++) {

            nodos = s.nextInt();
            aristas = s.nextInt();

            if (Grafo.tipoDeSustancia(nodos, aristas) == true) {
                // System.out.println("Sustancia pura");
            } else {

                // Grafo.determinarNumeroComponentes();
            }
        }
    }
}