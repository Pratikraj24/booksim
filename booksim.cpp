extern void CAARA_RoutingFunction(const Router *r, const Flit *f, int in_channel, OutputSet *outputs, bool inject);

void InitializeRoutingMap() {
    gRoutingFunctionMap["CAARA"] = &CAARA_RoutingFunction;
}
