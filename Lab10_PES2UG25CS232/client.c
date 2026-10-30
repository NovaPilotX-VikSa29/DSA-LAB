#include <stdio.h>
#include "graph.h"

static void build_graph(graph_t *g, int n_vertices, const int edges[][2], int edge_count)
{
    int i;

    init_graph(g, n_vertices, edge_count);
    for (i = 0; i < edge_count; ++i)
    {
        add_edge(g, edges[i][0], edges[i][1]);
    }
}

static void print_graph_results(const char *label, graph_t *g)
{
    int euler_result = check_eulerian(g);
    int star_hub = check_star(g);
    topology_t topology = identify_topology(g);

    printf("==== %s ====\n", label);
    disp(g);
    printf("Eulerian check   : ");
    if (euler_result == 2)
    {
        printf("Euler circuit exists\n");
    }
    else if (euler_result == 1)
    {
        printf("Euler path exists\n");
    }
    else
    {
        printf("Euler circuit does not exist\n");
    }

    printf("Star check       : ");
    if (star_hub == -1)
    {
        printf("Not a star\n");
    }
    else
    {
        printf("Star, hub = %c\n", 'A' + star_hub);
    }

    printf("Network topology : %s\n\n", topology_name(topology));
}

int main(void)
{
    graph_t handout_graph;
    graph_t cycle_5;
    graph_t path_4;
    graph_t star_graph;
    graph_t complete_5;
    graph_t binary_tree;
    graph_t bow_tie;
    graph_t disconnected;

    int handout_edges[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4},
                              {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}};
    int cycle_5_edges[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};
    int path_4_edges[][2] = {{0, 1}, {1, 2}, {2, 3}};
    int star_edges[][2] = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}};
    int complete_5_edges[][2] = {{0, 1}, {0, 2}, {0, 3}, {0, 4},
                                 {1, 2}, {1, 3}, {1, 4},
                                 {2, 3}, {2, 4},
                                 {3, 4}};
    int binary_tree_edges[][2] = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
    int bow_tie_edges[][2] = {{0, 1}, {1, 2}, {2, 0},
                             {0, 3}, {3, 4}, {4, 0}};
    int disconnected_edges[][2] = {{0, 1}, {1, 2}, {2, 0}, {3, 4}};

    build_graph(&handout_graph, 8, handout_edges, 11);
    build_graph(&cycle_5, 5, cycle_5_edges, 5);
    build_graph(&path_4, 4, path_4_edges, 3);
    build_graph(&star_graph, 6, star_edges, 5);
    build_graph(&complete_5, 5, complete_5_edges, 10);
    build_graph(&binary_tree, 7, binary_tree_edges, 6);
    build_graph(&bow_tie, 5, bow_tie_edges, 6);
    build_graph(&disconnected, 5, disconnected_edges, 4);

    print_graph_results("Handout graph", &handout_graph);
    print_graph_results("Cycle of 5", &cycle_5);
    print_graph_results("Path of 4", &path_4);
    print_graph_results("Star with 1 hub and 5 leaves", &star_graph);
    print_graph_results("Complete graph K5", &complete_5);
    print_graph_results("Binary tree, 7 vertices", &binary_tree);
    print_graph_results("Bow-tie", &bow_tie);
    print_graph_results("Disconnected graph", &disconnected);

    return 0;
}

