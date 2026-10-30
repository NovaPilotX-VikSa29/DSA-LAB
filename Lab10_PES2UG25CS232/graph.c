#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define DEBUG 0

static void dfs_recursive(graph_t *g, int visited[], int u)
{
    int i;

    visited[u] = 1;
    for (i = 0; i < g->n_vertices_; ++i)
    {
        if (g->adj_mat_[u][i] && !visited[i])
        {
            dfs_recursive(g, visited, i);
        }
    }
}

static int is_connected_non_isolated(graph_t *g)
{
    int visited[MAXSIZE] = {0};
    int start = -1;
    int i;

    if (g == NULL)
    {
        return 0;
    }

    for (i = 0; i < g->n_vertices_; ++i)
    {
        if (degree(g, i) > 0)
        {
            start = i;
            break;
        }
    }

    if (start == -1)
    {
        return 0;
    }

    dfs_recursive(g, visited, start);

    for (i = 0; i < g->n_vertices_; ++i)
    {
        if (degree(g, i) > 0 && !visited[i])
        {
            return 0;
        }
    }

    return 1;
}

/*
 * Initializes the graph structure and clears the adjacency matrix.
 * Parameters: ptr_graph - pointer to graph_t, n_vertices - vertex count, n_edges - edge count.
 * Return: none.
 */
void init_graph(graph_t *ptr_graph, int n_vertices, int n_edges)
{
    int i;
    int j;

    ptr_graph->n_vertices_ = n_vertices;
    ptr_graph->n_edges_ = n_edges;
    for (i = 0; i < ptr_graph->n_vertices_; ++i)
    {
        for (j = 0; j < ptr_graph->n_vertices_; ++j)
        {
            ptr_graph->adj_mat_[i][j] = 0;
        }
    }
}

/*
 * Adds an undirected edge between two vertices in the adjacency matrix.
 * Parameters: ptr_graph - graph_t pointer, from - source vertex, to - destination vertex.
 * Return: none.
 */
void add_edge(graph_t *ptr_graph, int from, int to)
{
    if (ptr_graph == NULL)
    {
        return;
    }

    if (DEBUG)
    {
        printf("Adding an edge %d - %d\n", from, to);
    }

    if (from < 0 || to < 0 || from >= ptr_graph->n_vertices_ || to >= ptr_graph->n_vertices_)
    {
        return;
    }

    ptr_graph->adj_mat_[from][to] = 1;
    ptr_graph->adj_mat_[to][from] = 1;
}

/*
 * Returns the degree of a vertex, defined as the sum of entries in that row.
 * Parameters: g - graph_t pointer, v - vertex index.
 * Return: degree of vertex v, or 0 when the vertex is invalid.
 */
int degree(graph_t *g, int v)
{
    int i;
    int deg = 0;

    if (g == NULL || v < 0 || v >= g->n_vertices_)
    {
        return 0;
    }

    for (i = 0; i < g->n_vertices_; ++i)
    {
        deg += g->adj_mat_[v][i];
    }

    return deg;
}

/*
 * Counts the total number of edges in the undirected graph by summing the upper triangle.
 * Parameters: g - graph_t pointer.
 * Return: total number of edges in g.
 */
int count_edges(graph_t *g)
{
    int i;
    int j;
    int count = 0;

    if (g == NULL)
    {
        return 0;
    }

    for (i = 0; i < g->n_vertices_; ++i)
    {
        for (j = i + 1; j < g->n_vertices_; ++j)
        {
            count += g->adj_mat_[i][j];
        }
    }

    return count;
}

/*
 * Performs a depth-first search from vertex u and prints the visit order.
 * Parameters: ptr_graph - graph_t pointer, u - starting vertex.
 * Return: none.
 */
void dfs(graph_t *ptr_graph, int u)
{
    int visited[MAXSIZE] = {0};
    int i;

    if (ptr_graph == NULL || u < 0 || u >= ptr_graph->n_vertices_)
    {
        return;
    }

    dfs_recursive(ptr_graph, visited, u);
    for (i = 0; i < ptr_graph->n_vertices_; ++i)
    {
        if (visited[i])
        {
            printf("visited %d\n", i);
        }
    }
    printf("\n");
}

/*
 * Returns 1 if every vertex is reachable from vertex 0, otherwise 0.
 * Parameters: g - graph_t pointer.
 * Return: 1 for connected, otherwise 0.
 */
int is_connected(graph_t *g)
{
    int visited[MAXSIZE] = {0};
    int i;

    if (g == NULL || g->n_vertices_ < 2)
    {
        return 0;
    }

    dfs_recursive(g, visited, 0);

    for (i = 0; i < g->n_vertices_; ++i)
    {
        if (!visited[i])
        {
            return 0;
        }
    }

    return 1;
}

/*
 * Displays the adjacency matrix with A, B, C... labels for the rows and columns.
 * Parameters: ptr_graph - graph_t pointer.
 * Return: none.
 */
void disp(graph_t *ptr_graph)
{
    int i;
    int j;

    if (ptr_graph == NULL)
    {
        return;
    }

    printf("    ");
    for (j = 0; j < ptr_graph->n_vertices_; ++j)
    {
        printf("%2c ", 'A' + j);
    }
    printf("\n");

    for (i = 0; i < ptr_graph->n_vertices_; ++i)
    {
        printf("%c  ", 'A' + i);
        for (j = 0; j < ptr_graph->n_vertices_; ++j)
        {
            printf("%2d ", ptr_graph->adj_mat_[i][j]);
        }
        printf("\n");
    }
}

/*
 * Determines whether the graph is Eulerian: 2 for a circuit, 1 for a path only, 0 otherwise.
 * Parameters: g - graph_t pointer.
 * Return: 2 for Euler circuit, 1 for Euler path, 0 otherwise.
 */
int check_eulerian(graph_t *g)
{
    int odd_count = 0;
    int i;
    int edge_count;

    if (g == NULL || g->n_vertices_ == 0)
    {
        return 0;
    }

    edge_count = count_edges(g);
    if (edge_count == 0)
    {
        return 0;
    }

    for (i = 0; i < g->n_vertices_; ++i)
    {
        if (degree(g, i) == 0)
        {
            continue;
        }
        if (degree(g, i) % 2 != 0)
        {
            odd_count++;
        }
    }

    if (odd_count == 0)
    {
        if (is_connected_non_isolated(g))
        {
            return 2;
        }
        return 0;
    }

    if (odd_count == 2 && is_connected_non_isolated(g))
    {
        return 1;
    }

    return 0;
}

/*
 * Finds the hub vertex if the graph is a star topology, otherwise returns -1.
 * Parameters: g - graph_t pointer.
 * Return: hub vertex index, or -1 when g is not a star.
 */
int check_star(graph_t *g)
{
    int n;
    int hub = -1;
    int i;

    if (g == NULL || g->n_vertices_ < 3)
    {
        return -1;
    }

    n = g->n_vertices_;
    for (i = 0; i < n; ++i)
    {
        if (degree(g, i) == n - 1)
        {
            hub = i;
            break;
        }
    }

    if (hub == -1)
    {
        return -1;
    }

    for (i = 0; i < n; ++i)
    {
        if (i == hub)
        {
            continue;
        }
        if (degree(g, i) != 1 || g->adj_mat_[hub][i] != 1)
        {
            return -1;
        }
    }

    return hub;
}

/*
 * Identifies the network topology of a connected graph using the required precedence.
 * Parameters: g - graph_t pointer.
 * Return: topology_t enum value describing the graph.
 */
topology_t identify_topology(graph_t *g)
{
    int n;
    int i;
    int edge_count;
    int degree_one_count = 0;
    int degree_two_count = 0;
    int all_mates = 1;

    if (g == NULL || g->n_vertices_ < 2)
    {
        return NOT_NETWORK;
    }

    if (!is_connected(g))
    {
        return NOT_NETWORK;
    }

    n = g->n_vertices_;
    edge_count = count_edges(g);

    if (n >= 3)
    {
        int is_ring = 1;
        for (i = 0; i < n; ++i)
        {
            if (degree(g, i) != 2)
            {
                is_ring = 0;
                break;
            }
        }
        if (is_ring && edge_count == n)
        {
            return RING;
        }
    }

    if (edge_count == n - 1)
    {
        for (i = 0; i < n; ++i)
        {
            if (degree(g, i) == 1)
            {
                degree_one_count++;
            }
            else if (degree(g, i) == 2)
            {
                degree_two_count++;
            }
        }
        if (degree_one_count == 2 && degree_two_count == n - 2)
        {
            return BUS;
        }
    }

    if (check_star(g) != -1)
    {
        return STAR;
    }

    if (n >= 2)
    {
        all_mates = 1;
        for (i = 0; i < n; ++i)
        {
            if (degree(g, i) != n - 1)
            {
                all_mates = 0;
                break;
            }
        }
        if (all_mates)
        {
            return FULL_MESH;
        }
    }

    if (edge_count == n - 1)
    {
        return TREE;
    }

    return HYBRID;
}

/*
 * Returns a printable name for each topology enum value.
 * Parameters: t - topology_t value.
 * Return: string representation of the topology.
 */
const char *topology_name(topology_t t)
{
    switch (t)
    {
        case RING:
            return "Ring";
        case BUS:
            return "Bus";
        case STAR:
            return "Star";
        case FULL_MESH:
            return "Full Mesh";
        case TREE:
            return "Tree";
        case HYBRID:
            return "Hybrid";
        case NOT_NETWORK:
            return "Not a network";
        default:
            return "Unknown";
    }
}

/*
 * Resets the graph by clearing its vertex and edge counters and its adjacency matrix.
 * Parameters: ptr_graph - graph_t pointer.
 * Return: none.
 */
void deinit_graph(graph_t *ptr_graph)
{
    int i;
    int j;

    if (ptr_graph == NULL)
    {
        return;
    }

    ptr_graph->n_vertices_ = 0;
    ptr_graph->n_edges_ = 0;
    for (i = 0; i < MAXSIZE; ++i)
    {
        for (j = 0; j < MAXSIZE; ++j)
        {
            ptr_graph->adj_mat_[i][j] = 0;
        }
    }
}
