void mazeSoluation() {
  bool terminator = true;
  while (terminator) {
    terminator = false;
    for (int i = 0; i < 6; i++) {
      if (dir == 'L') {
        while (path.indexOf(leftRule[i][0]) != -1) {
          path = path.substring(0, path.indexOf(leftRule[i][0])) + leftRule[i][1] + path.substring(path.indexOf(leftRule[i][0]) + 3, path.length());
          terminator = true;
        }
      } else {
        while (path.indexOf(rightRule[i][0]) != -1) {
          path = path.substring(0, path.indexOf(rightRule[i][0])) + rightRule[i][1] + path.substring(path.indexOf(rightRule[i][0]) + 3, path.length());
          terminator = true;
        }
      }
    }
  }

  if (reverseMethode) {
    String rPath = path;
    int pathLen = path.length();
    for (int i = 0; i < pathLen; i++) {
      if (rPath[(pathLen - 1) - i] == 'L')
        path[i] = 'R';
      else if (rPath[(pathLen - 1) - i] == 'R')
        path[i] = 'L';
      else if (rPath[(pathLen - 1) - i] == 'S')
        path[i] = 'S';
    }
  }
}
