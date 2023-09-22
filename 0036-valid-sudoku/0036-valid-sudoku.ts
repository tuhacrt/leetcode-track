function isValidSudoku(board: string[][]): boolean {
  const [r, c] = [board.length, board[0].length];
  
  for (let i = 0; i < r; i++) {
    let set = new Set();
    for (let j = 0; j < c; j++) {
      if (board[i][j] === '.') continue;
      if (set.has(board[i][j])) return false;
      set.add(board[i][j]);
    }
  }
  
  for (let i = 0; i < c; i++) {
    let set = new Set();
    for (let j = 0; j < r; j++) {
      if (board[j][i] === '.') continue;
      if (set.has(board[j][i])) return false;
      set.add(board[j][i]);
    }
  }
  
  for (let rs = 0; rs < 3; rs ++) {
    for (let cs = 0; cs < 3; cs++) {
      let set = new Set();
      for (let i = rs * 3; i < rs * 3 + 3; i++) {
        for (let j = cs * 3; j < cs * 3 + 3; j++) {
          if (board[i][j] === '.') continue;
          if (set.has(board[i][j])) return false;
          set.add(board[i][j]);
    }
  }
    }
  }
  
  return true;
};