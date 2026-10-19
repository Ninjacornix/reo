// Experimental packet-local ordered primitive metadata. No live ABI change.
struct TriangleBatchState {
    GS* owner = nullptr;
    unsigned depth = 0, count = 0;
    std::array<std::array<GSVertex, 3>, 64> triangles{};
    std::function<void()> render;
};
thread_local TriangleBatchState t_triangleBatch;
thread_local const GSVertex* t_batchVertices = nullptr;
thread_local bool t_batchRowClip = false;
thread_local int t_batchY0 = 0, t_batchY1 = 0;
std::atomic<uint64_t> s_batchParallel{0}, s_batchParallelTriangles{0}, s_batchSerialTriangles{0};
// Isolated deterministic cancellation oracle. Set only before/after joined
// packets; zero in benchmarks. No per-pixel instrumentation is introduced.
uint64_t s_batchTestRowLimit = 0;
std::atomic<uint64_t> s_batchTestRows{0};
std::atomic<bool> s_batchTestCancelled{false};
bool triangleBatchTestCancelRow() {
    if (!s_batchTestRowLimit)
        return false;
    if (s_batchTestCancelled.load(std::memory_order_relaxed))
        return true;
    if (s_batchTestRows.fetch_add(1, std::memory_order_relaxed) >= s_batchTestRowLimit) {
        s_batchTestCancelled.store(true, std::memory_order_relaxed);
        return true;
    }
    return false;
}
bool triangleBatchEnabled() {
    static const bool enabled = [] {
        const char* value = std::getenv("REO_GS_TRI_BATCH");
        return value && std::atoi(value) != 0 && !std::getenv("REO_GS_TRI_PROBE_AT") &&
               !std::getenv("REO_GS_PIPELINE_AT");
    }();
    return enabled;
}
void flushTriangleBatch(GS* gs) {
    auto& b = t_triangleBatch;
    if (b.owner != gs || !b.count)
        return;
    // Copy the callback, not GS/state. It remains valid through joined work.
    auto render = b.render;
    if (!ps2GsWorkerStopRequested() && render)
        render();
    b.count = 0;
    b.render = {};
}
struct BatchTriangleScope {
    const GSVertex* previous = t_batchVertices;
    bool oldClip = t_batchRowClip;
    int oldY0 = t_batchY0, oldY1 = t_batchY1;
    BatchTriangleScope(const GSVertex* vertices, bool clip, int y0, int y1) {
        t_batchVertices = vertices;
        t_batchRowClip = clip;
        t_batchY0 = y0;
        t_batchY1 = y1;
    }
    ~BatchTriangleScope() {
        t_batchVertices = previous;
        t_batchRowClip = oldClip;
        t_batchY0 = oldY0;
        t_batchY1 = oldY1;
    }
};
