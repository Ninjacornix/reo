std::uint64_t control_flush_cases{}, control_flush_packets{}, control_payload_reset_cases{};

struct PayloadCapture final : ai::ControlPayloadSink {
    std::array<ai::ControlPayloadPacket, 64> packets{};
    std::size_t accepted{}, limit{packets.size()};

    bool send_control_payload(const ai::ControlPayloadPacket& packet) noexcept override {
        if (accepted == limit)
            return false;
        packets[accepted++] = packet;
        return true;
    }
};

#ifdef REO_AI_ORIGINAL
bool reference_payloads_active{};
PayloadCapture reference_payloads;

void record_original_control_payload(std::uint8_t* bytes, R5900Context* context) {
    check(reference_payloads_active && GPR_U32(context, 4) == 10 && GPR_U32(context, 6) == 0 &&
          GPR_U32(context, 7) == 4);
    const auto packet = transform_read<ai::ControlPayloadPacket>(bytes, GPR_U32(context, 5));
    check(reference_payloads.send_control_payload(packet));
    context->pc = GPR_U32(context, 31);
}
#endif

ai::ControlRequests make_payload_queue(unsigned count, std::uint8_t actor) {
    ai::ControlRequests controls;
    for (unsigned i = 0; i < 64; ++i) {
        check(controls.register_control(0, i) == ai::RegistrationStatus::created);
        auto& entry = *controls.registration(i);
        entry.phase = std::uint8_t(i ^ actor);
        entry.payload = {1, 2, 3, 4};
        entry.counters.fill(4321);
    }
    for (unsigned i = 0; i < count; ++i) {
        const auto slot = (i * 5 + actor) % 64;
        const auto result = controls.request(0, slot, {std::uint8_t(i), actor, 100, 0xff});
        check(result.status == ai::RequestStatus::queued && result.registration == slot);
    }
    return controls;
}

void compare_control_flush(unsigned count, std::uint8_t actor, bool reset = false) {
    auto controls = make_payload_queue(count, actor);
    PayloadCapture sink;
#ifdef REO_AI_ORIGINAL
    constexpr unsigned at = 0x7449b0, extent = 328 + 64 * 28;
    std::fill_n(memory.begin() + at, extent, 0xa5);
    project_controls(memory, at, controls);
    put(memory, at + 4, reset ? 19u : 0u);
    auto expected = std::vector<std::uint8_t>(memory.begin() + at, memory.begin() + at + extent);
    memory[0x3243f2] = 0;
    memory[0x83e2d5] = 0;
    memory[0x4baded] = actor;
#endif
    if (reset) {
        check(controls.reset_pending_payloads() && controls.pending().empty());
        ++control_payload_reset_cases;
    } else {
        const auto result = controls.flush_payloads(actor, sink);
        check(result.status == ai::ControlPayloadStatus::completed && result.sent == count &&
              controls.pending().empty());
        check(sink.accepted == count);
        ++control_flush_cases;
        control_flush_packets += count;
    }
#ifdef REO_AI_ORIGINAL
    project_controls(expected, 0, controls);
    put(expected, 4, 0u);
    R5900Context context;
    PS2Runtime runtime;
    context.pc = reset ? 0x6816f0 : 0x6814e0;
    SET_GPR_U32(&context, 29, 0x1f00000);
    SET_GPR_U32(&context, 31, 0x100);
    reference_payloads.accepted = 0;
    reference_payloads_active = true;
    original_transform_port(memory.data(), &context, &runtime);
    reference_payloads_active = false;
    check(context.pc == 0x100 && GPR_U32(&context, 29) == 0x1f00000);
    check(std::memcmp(expected.data(), memory.data() + at, extent) == 0);
    check(sink.accepted == reference_payloads.accepted);
    for (std::size_t i = 0; i < sink.accepted; ++i)
        check(sink.packets[i] == reference_payloads.packets[i]);
#endif
}

void control_payload_contracts() {
    for (unsigned count = 0; count <= 64; ++count) {
        for (std::uint8_t actor : {0, 7, 128, 255})
            compare_control_flush(count, actor);
        compare_control_flush(count, std::uint8_t(count), true);
    }
    for (unsigned actor = 0; actor < 256; ++actor)
        compare_control_flush(1, std::uint8_t(actor));

    auto controls = make_payload_queue(5, 1);
    PayloadCapture sink;
    sink.limit = 2;
    const auto rejected = controls.flush_payloads(1, sink);
    check(rejected.status == ai::ControlPayloadStatus::send_failed && rejected.sent == 2);
    check(controls.pending().size() == 3 && controls.pending().front().payload[0] == 2);
    sink.limit = 5;
    const auto retried = controls.flush_payloads(1, sink);
    check(retried.status == ai::ControlPayloadStatus::completed && retried.sent == 3);
    check(sink.accepted == 5 && controls.pending().empty());
    for (unsigned i = 0; i < sink.accepted; ++i)
        check(sink.packets[i] == ai::ControlPayloadPacket{0, 9, 0x81, 0, std::uint8_t(i * 5 + 1),
                                                          std::uint8_t(i), 1, 100, 0xff});
}
