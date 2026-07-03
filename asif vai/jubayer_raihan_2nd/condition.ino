bool right90() {
  if (Read == 45678 || Read == 5678 || Read == 678 || Read == 345600 )
    return true;
  else
    return false;
}

bool left90() {
  if (Read == 12345000 || Read == 12340000 || Read == 12300000)
    return true;
  else
    return false;
}


bool blackCondition() {
  if (Read == 12345678 || Read == 12345670 || Read == 2345678)
    return true;
  else
    return false;
}



bool left45() {
  if (Read == 12040000 ||
      Read == 10000600 ||
      Read == 10005600 ||
      Read == 10005000 ||
      Read == 10045000 ||
      Read == 10040000 ||
      Read == 12000600 ||
      Read == 12005600 ||
      Read == 12005000 ||
      Read == 12045000)
    return true;
  else
    return false;
}
bool right45() {
  if (Read == 340008||
    Read == 40008  ||
    Read == 45008  ||
    Read == 5008   ||
    Read == 5608   ||
    Read == 340078 ||
    Read == 40078  ||
    Read == 45078  ||
    Read == 5078   ||
    Read == 45070  ||
    Read == 40070)
    return true;
  else
    return false;
}


bool starCondition() {
  if (
    Read == 10000008 ||
    Read == 12000008 ||
    Read == 10000078 ||
    Read == 12000078 ||
    Read == 2300670 ||
    Read == 2000670 ||
    Read == 2300070 ||

    Read == 2000070 ||
    Read == 300600 ||
    Read == 2300670 ||
    Read == 12005670 ||
    Read == 2300078
  )
    return true;
  else
    return false;
}

bool Tcondition() {
  if ((
        Read == 12345670 ||
        Read == 2345678  ||
        Read == 12345678
      ) &&
      Read == 0
     )
    return true;
  else
    return false;
}

bool plusCondition() {
  if (
    Read == 12345670 ||
    Read == 2345678  ||
    Read == 12345678
  )

    return true;
  else
    return false;
}

// bool whiteCondition() {
//   if (Read == 0 || Read == 10000000 || Read == 8)
//     return true;
//   else
//     return false;
// }

