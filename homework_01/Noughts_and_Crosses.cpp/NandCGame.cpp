#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <string>
#include <vector>

// enumerations
enum class Field { Free, Nought, Cross };

enum class GameState { Running, Draw, N_wins, C_wins };

// functions
int Randint(int min, int max) { return rand() % (max - min + 1) + min; }

std::vector<std::string> SplitString(const std::string& str) {
  std::vector<char> braces;
  std::vector<std::string> result;
  std::string temp;
  for (auto c : str) {
    if (c != ' ' && c != '\t') {
      temp += c;
    } else if (braces.size() != 0) {
      temp += c;
    } else if (!temp.empty()) {
      result.push_back(temp);
      temp.clear();
    }
    if (c == '(') {
      braces.push_back(c);
    } else if (braces.size() > 0 && c == ')') {
      if (braces.back() == '(') {
        braces.pop_back();
      }
    }
  }
  if (!temp.empty()) {
    result.push_back(temp);
  }
  return result;
}

std::string GStoS(GameState f) {
  if (f == GameState::Running) {
    return "Running";
  } else if (f == GameState::Draw) {
    return "Draw";
  } else if (f == GameState::N_wins) {
    return "Noughts win";
  } else if (f == GameState::C_wins) {
    return "Crosses win";
  }
}

class NandCGrid {
 public:
  Field Get(int x, int y) const { return m_grid[x][y]; }
  void Set(int x, int y, Field f) { m_grid[x][y] = f; }
  GameState GetState() const {
    if ((m_grid[0][0] == m_grid[1][1]) && (m_grid[1][1] == m_grid[2][2])) {
      if (m_grid[0][0] == Field::Nought) {
        return GameState::N_wins;
      } else if (m_grid[0][0] == Field::Cross) {
        return GameState::C_wins;
      } else {
        return GameState::Running;
      }
    }
    if ((m_grid[0][2] == m_grid[1][1]) && (m_grid[1][1] == m_grid[2][0])) {
      if (m_grid[0][2] == Field::Nought) {
        return GameState::N_wins;
      } else if (m_grid[0][2] == Field::Cross) {
        return GameState::C_wins;
      } else {
        return GameState::Running;
      }
    }
    for (int i = 0; i < 3; ++i) {
      if ((m_grid[i][0] == m_grid[i][1]) && (m_grid[i][1] == m_grid[i][2])) {
        if (m_grid[i][0] == Field::Nought) {
          return GameState::N_wins;
        } else if (m_grid[i][0] == Field::Cross) {
          return GameState::C_wins;
        } else {
          return GameState::Running;
        }
      } else if ((m_grid[0][i] == m_grid[1][i]) &&
                 (m_grid[1][i] == m_grid[2][i])) {
        if (m_grid[0][i] == Field::Nought) {
          return GameState::N_wins;
        } else if (m_grid[0][i] == Field::Cross) {
          return GameState::C_wins;
        } else {
          return GameState::Running;
        }
      }
    }
    for (int i = 0; i < 3; ++i) {
      int f_cnt = 0;
      int n_cnt = 0;
      int c_cnt = 0;
      for (int j = 0; j < 3; ++j) {
        if (m_grid[i][j] == Field::Free) {
          f_cnt += 1;
        } else if (m_grid[i][j] == Field::Nought) {
          n_cnt += 1;
        } else {
          n_cnt += 1;
        }
      }
      if (f_cnt >= 2) {
        return GameState::Running;
      } else if ((n_cnt == 2) || (c_cnt == 2)) {
        return GameState::Running;
      }

      f_cnt = 0;
      n_cnt = 0;
      c_cnt = 0;
      for (int j = 0; j < 3; ++j) {
        if (m_grid[j][i] == Field::Free) {
          f_cnt += 1;
        } else if (m_grid[j][i] == Field::Nought) {
          n_cnt += 1;
        } else {
          n_cnt += 1;
        }
      }
      if (f_cnt >= 2) {
        return GameState::Running;
      } else if ((n_cnt == 2) || (c_cnt == 2)) {
        return GameState::Running;
      }
    }
    return GameState::Draw;
  }
  std::string ToString() const {
    std::string field;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (m_grid[i][j] == Field::Free) {
          field += " * ";
        } else if (m_grid[i][j] == Field::Cross) {
          field += " x ";
        } else {
          field += " o ";
        }
      }
      field += "\n";
    }
    return field;
  }

  friend std::ostream& operator<<(std::ostream& stream, NandCGrid& grid);

 private:
  Field m_grid[3][3];
};

std::ostream& operator<<(std::ostream& stream, NandCGrid& grid) {
  stream << grid.ToString();
  return stream;
}

class Player {
 public:
  Player(std::string name, Field f) {
    m_type = f;
    m_name = name;
  }
  std::pair<int, int> p;

  bool MakeMove(NandCGrid& grid) {
    std::cout << grid << "\n";
    std::cout << m_name << " is making a move: ";
    while (true) {
      std::string responce;
      std::getline(std::cin, responce);
      std::vector<std::string> vect = SplitString(responce);
      std::pair<int, int> p;
      p.first = std::stoi(vect.at(0)) - 1;
      p.second = std::stoi(vect.at(1)) - 1;
      if (grid.Get(p.first, p.second) == Field::Free) {
        grid.Set(p.first, p.second, m_type);
        return false;
      } else {
        std::cout << "This cell is already assigned\n";
        std::cout << grid << "\n";
      }
    }
  }

 private:
  Field m_type;
  std::string m_name;
};

class NandCGame {
 public:
  NandCGame() {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        m_grid.Set(i, j, Field::Free);
      }
    }
  }

  void Run() {
    std::cout << "Enter participants (robot or human):\n";
    std::string responce;
    std::getline(std::cin, responce);
    std::vector<std::string> vect = SplitString(responce);
    Player pl1("pl1", Field::Cross);
    Player pl2("pl2", Field::Nought);
    while (m_grid.GetState() == GameState::Running) {
      pl1.MakeMove(m_grid);
      if (m_grid.GetState() == GameState::Running) {
        pl2.MakeMove(m_grid);
        std::cout << GStoS(m_grid.GetState()) << "\n";
        continue;
      }
      std::cout << GStoS(m_grid.GetState()) << "\n";
    }
    std::cout << m_grid;
  }

 private:
  NandCGrid m_grid;
};

int main() {
  std::cout << std::endl;
  NandCGame a;
  a.Run();
  return 0;
}