if (triangleBatchEnabled() && t_triangleBatch.owner == gs && t_triangleBatch.depth == 1) {
    auto& b = t_triangleBatch;
    if (b.count == b.triangles.size())
        flushTriangleBatch(gs);
    if (!b.count)
        b.render = [this, gs] {
            auto& batch = t_triangleBatch;
            const unsigned count = batch.count;
            const auto& context = gs->activeContext();
            int x0 = INT_MAX, y0 = INT_MAX, x1 = INT_MIN, y1 = INT_MIN;
            uint64_t work = 0;
            bool geometry = true;
            std::array<std::pair<int, int>, 64> rowBounds{};
            const int ofx = context.xyoffset.ofx >> 4, ofy = context.xyoffset.ofy >> 4;
            for (unsigned i = 0; i < count; ++i) {
                const auto& vertices = batch.triangles[i];
                for (const auto& v : vertices)
                    if (!std::isfinite(v.x) || !std::isfinite(v.y) || std::fabs(v.x) > 1048576.f ||
                        std::fabs(v.y) > 1048576.f)
                        geometry = false;
                if (!geometry)
                    break;
                int ax = clampInt(
                    int(std::floor(std::min({vertices[0].x, vertices[1].x, vertices[2].x}) -
                                   float(ofx))),
                    context.scissor.x0, context.scissor.x1);
                int bx =
                    clampInt(int(std::ceil(std::max({vertices[0].x, vertices[1].x, vertices[2].x}) -
                                           float(ofx))),
                             context.scissor.x0, context.scissor.x1);
                int ay = clampInt(
                    int(std::floor(std::min({vertices[0].y, vertices[1].y, vertices[2].y}) -
                                   float(ofy))),
                    context.scissor.y0, context.scissor.y1);
                int by =
                    clampInt(int(std::ceil(std::max({vertices[0].y, vertices[1].y, vertices[2].y}) -
                                           float(ofy))),
                             context.scissor.y0, context.scissor.y1);
                rowBounds[i] = {ay, by};
                x0 = std::min(x0, ax);
                x1 = std::max(x1, bx);
                y0 = std::min(y0, ay);
                y1 = std::max(y1, by);
                work += uint64_t(bx - ax + 1) * uint64_t(by - ay + 1);
            }
            // One wake/join for enough real bbox work, never a sparse union alone.
            bool parallel = geometry && count >= 8 && work >= 4096 && y1 - y0 >= 16;
            if (parallel)
                for (unsigned i = 0; i < count; ++i)
                    if (!triangleBatchSafe(context, gs->m_prim, batch.triangles[i].data(),
                                           gs->m_texclut, gs->m_vramSize, x0, y0, x1, y1)) {
                        parallel = false;
                        break;
                    }
            if (parallel) {
                ++s_batchParallel;
                s_batchParallelTriangles.fetch_add(count, std::memory_order_relaxed);
                const auto bands = [&](int begin, int end) {
                    const TriangleBandTlsScope tls(true, nullptr);
                    // All triangles are visited in their original order in every
                    // unique physical row domain. State remains worker-owned.
                    for (unsigned i = 0; i < count && !ps2GsWorkerStopRequested(); ++i) {
                        if (rowBounds[i].second < begin || rowBounds[i].first > end)
                            continue;
                        const PixelDepthScope primitiveDepth;
                        const BatchTriangleScope scope(batch.triangles[i].data(), true, begin, end);
                        drawTriangle(gs);
                    }
                };
                RowPool::get().run(y0, y1, bands);
            } else {
                s_batchSerialTriangles.fetch_add(count, std::memory_order_relaxed);
                for (unsigned i = 0; i < count && !ps2GsWorkerStopRequested(); ++i) {
                    const PixelDepthScope primitiveDepth;
                    const BatchTriangleScope scope(batch.triangles[i].data(), false, 0, 0);
                    drawTriangle(gs);
                }
            }
        };
    // Copy before strip/fan/ADC assembly consumes or replaces any vertex.
    std::copy_n(gs->m_vtxQueue, 3, b.triangles[b.count++].begin());
} else
    drawTriangle(gs);
