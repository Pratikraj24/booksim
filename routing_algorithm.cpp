#include <algorithm>
#include <vector>

double CalculatePathCost(int path, double local_congestion, double global_congestion) {
    return local_congestion + global_congestion;
}

void CAARA_RoutingFunction(const Router *r, const Flit *f, int in_channel, OutputSet *outputs, bool inject) {
    double local_congestion = r->GetLocalCongestion();
    double global_congestion = r->GetGlobalCongestion();

    std::vector<int> possible_paths = r->GetPossiblePaths(f->dest);
    std::vector<double> path_costs;

    for (auto path : possible_paths) {
        double path_cost = CalculatePathCost(path, local_congestion, global_congestion);
        path_costs.push_back(path_cost);
    }

    int best_path = std::min_element(path_costs.begin(), path_costs.end()) - path_costs.begin();

    outputs->Clear();
    outputs->AddRange(possible_paths[best_path], 1, 0);
}
