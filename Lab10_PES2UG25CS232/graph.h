#ifndef GRAPH_H
#define GRAPH_H

#define MAXSIZE 10

enum topology {
    RING,
    BUS,
    STAR,
    FULL_MESH,
    TREE,
    HYBRID,
    NOT_NETWORK
};
typedef enum topology topology_t;

struct graph
{
    int n_vertices_; /* # of vertices */
    int n_edges_; /* # of edges */
    int adj_mat_[MAXSIZE][MAXSIZE];
};
typedef struct graph graph_t;

void init_graph(graph_t *ptr_graph, int n_vertices, int n_edges);
void add_edge(graph_t *ptr_graph, int from, int to);
void dfs(graph_t *ptr_graph, int u);
void disp(graph_t *ptr_graph);
void deinit_graph(graph_t *ptr_graph);
int degree(graph_t *g, int v);
int count_edges(graph_t *g);
int is_connected(graph_t *g);
int check_eulerian(graph_t *g);
int check_star(graph_t *g);
topology_t identify_topology(graph_t *g);
const char *topology_name(topology_t t);

#endif
