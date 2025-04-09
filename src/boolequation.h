#ifndef BOOLEQUATION_H
#define BOOLEQUATION_H

#include "boolinterval.h"
#include "BBV.h"


// Добавим enum для стратегии ветвления
enum BranchingStrategy {
    ROW_BRANCHING,
    COLUMN_BRANCHING
};

class BoolEquation {
public:
    BoolInterval **cnf;
    BoolInterval *root;
    int cnfSize;
    int count;
    BBV mask;
    int forcedBranchColumn;
    BranchingStrategy branchingStrategy;

    BoolEquation(BoolInterval **cnf, BoolInterval *root, int cnfSize, int count, BBV mask, BranchingStrategy strategy);
    BoolEquation(BoolEquation &equation);

    int CheckRules();
    int ChooseColForBranching();
    int ChooseRowForBranching(); // Выбор строки для ветвления
    int ChooseBranchingIndex(); // Обобщенный метод выбора с учетом стратегии
    void SetBranchingStrategy(BranchingStrategy strategy); // Установка стратегии

    void Simplify(int ixCol, char value);

private:
    bool Rule2RowNull(BoolInterval *interval);
    bool Rule1Row1(BoolInterval *interval);
    void Rule3ColNull(BBV vector);
    bool Rule4Col0(BBV vector);
    bool Rule5Col1(BBV vector);
};

#endif // BOOLEQUATION_H
