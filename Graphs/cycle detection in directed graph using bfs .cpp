// cycle detection in directed graph using bfs 
// Kahn's Algorithm

function topoSort(adj) {
    n = adj.length
    let indegree = new Array(n).fill(0);
    let queue = [];
    let res = [];

    // Compute indegrees
    for (let i = 0; i < n; i++) {
        for (let next of adj[i]) indegree[next]++;
    }

    // Add all nodes with indegree 0 
    // into the queue
    for (let i = 0; i < n; i++) {
        if (indegree[i] === 0) queue.push(i);
    }

    // Kahn’s Algorithm
    while (queue.length > 0) {
        let top = queue.shift();
        res.push(top);
        for (let next of adj[top]) {
            indegree[next]--;
            if (indegree[next] === 0) queue.push(next);
        }
    }

    return res;
}
