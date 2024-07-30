double Router::GetLocalCongestion() const {
    double local_congestion = 0.0;
    for (int i = 0; i < _inputs; ++i) {
        local_congestion += _buffer[i]->GetOccupancy();
    }
    return local_congestion / _inputs;
}

double Router::GetGlobalCongestion() const {
    double global_congestion = 0.0;
    // Logic to gather global congestion information (e.g., from neighboring routers)
    return global_congestion;
}
