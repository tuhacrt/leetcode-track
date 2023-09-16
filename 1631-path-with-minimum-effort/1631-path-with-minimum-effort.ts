const dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]];

const isValidGenerator = (row: number, col: number) => 
    (x: number, y: number) => x >= 0 && x <= row - 1 && y >= 0 && y <= col - 1;

const minimumEffortPath = (h: Array<Array<number>>): number => {
    const [row, col] = [h.length, h[0].length];
    // differenceMatrix
    const dM = Array.from({ length: row }, () => Array(col).fill(Infinity));
    dM[0][0] = 0;
    const pq = new MinPriorityQueue({ priority: ({ value }) => value });
    const visited = Array.from({ length: row }, () => Array(col).fill(false));
    const isValid = isValidGenerator(row, col);
    pq.enqueue({x: 0, y: 0, value: dM[0][0]});

    while (pq.size()) {
        const { element: { x, y, value } } = pq.dequeue();
        visited[x][y] = true;
        if (x === row - 1 && y === col -1) return value;
        
        for (const [nx, ny] of dirs) {
            // adjacent
            const ax = x + nx;
            const ay = y + ny;
            if (isValid(ax, ay) && !visited[ax][ay]) {
                const currentDifference = Math.abs(h[ax][ay] - h[x][y]);
                const maxDifference = Math.max(currentDifference, dM[x][y]);
                if (dM[ax][ay] > maxDifference) {
                    dM[ax][ay] = maxDifference;
                    pq.enqueue({x:ax, y:ay, value: maxDifference});
                }
            }
        }
    }
    
    return dM[row - 1][col - 1];
};