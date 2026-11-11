#include "script_program.hpp"
#include "script_flow.hpp"
#include <algorithm>
#include <deque>
#include <set>
#include <stdexcept>
#include <tuple>

namespace reo::native::gameplay_scenario::content {
namespace {
using detail::ScriptFlow;
constexpr std::size_t work_limit = 20000, scan_limit = 4096;

std::uint32_t read_word(std::span<const std::byte> bytes) noexcept {
    return std::to_integer<std::uint32_t>(bytes[0]) |
           std::to_integer<std::uint32_t>(bytes[1]) << 8 |
           std::to_integer<std::uint32_t>(bytes[2]) << 16 |
           std::to_integer<std::uint32_t>(bytes[3]) << 24;
}

struct State {
    Position pc;
    Position saved;
    std::uint32_t table_index{}, condition{};
    auto key() const noexcept {
        return std::tie(pc.block, pc.offset, saved.block, saved.offset, table_index, condition);
    }
    bool operator<(const State& other) const noexcept { return key() < other.key(); }
};

struct Failure {
    ScriptAdmission status;
    Position at;
    std::uint32_t opcode{};
};

class Closure {
public:
    Closure(const ScriptBank& bank, DispatchProfile profile)
        : profile_(profile), coverage_(Interpreter::coverage(profile)),
          blocks_(bank.table_size()), used_(bank.table_size()) {
        for (const auto& object : bank.executable_candidates())
            blocks_[object.table_index] = bank.view(object);
    }

    std::shared_ptr<const Program> build(const std::array<std::optional<Position>, 2>& entries) {
        for (const auto& entry : entries)
            if (entry) enqueue({*entry, {}, entry->block, 0});
        while (!pending_.empty()) {
            const auto state = pending_.front();
            pending_.pop_front();
            visit(state);
        }
        std::vector<std::vector<std::byte>> blocks(blocks_.size());
        for (std::size_t i = 0; i < blocks_.size(); ++i) {
            const auto extent = blocks_[i].first(used_[i]);
            blocks[i].assign(extent.begin(), extent.end());
        }
        auto program = std::make_shared<const Program>(Program::from_script_blocks(std::move(blocks), profile_));
        if (program->unsupported()) throw Failure{ScriptAdmission::unsupported_opcode, {}};
        return program;
    }

private:
    Record read(Position at) {
        if (at.block >= blocks_.size() || blocks_[at.block].empty())
            throw Failure{ScriptAdmission::unbound_block, at};
        const auto block = blocks_[at.block];
        if (at.offset > block.size() || block.size() - at.offset < 4)
            throw Failure{ScriptAdmission::invalid_record, at};
        const auto header = read_word(block.subspan(at.offset));
        const auto opcode = header & 0xffffff;
        const auto size = Program::record_bytes(header);
        if (!size || size > block.size() - at.offset || opcode >= coverage_.size())
            throw Failure{ScriptAdmission::invalid_record, at, opcode};
        if (!coverage_[opcode].native_algorithm)
            throw Failure{ScriptAdmission::unsupported_opcode, at, opcode};
        const auto payload = block.subspan(at.offset + 4, size - 4);
        if (payload.size() < detail::script_flow_binding(opcode, profile_).minimum_payload)
            throw Failure{ScriptAdmission::invalid_payload, at, opcode};
        used_[at.block] = std::max(used_[at.block], at.offset + size);
        return {opcode, size, payload};
    }

    void enqueue(State state) {
        if (!seen_.insert(state).second) return;
        if (seen_.size() > work_limit) throw Failure{ScriptAdmission::work_limit, state.pc};
        pending_.push_back(state);
    }

    State scan(State state, bool failed) {
        const auto start = state.pc;
        const auto saved = state.condition;
        state.pc.offset += read(state.pc).bytes;
        for (std::size_t step = 0; step < scan_limit; ++step) {
            const auto record = read(state.pc);
            state.condition += detail::script_flow_binding(record.opcode, profile_).opens_condition;
            if (failed && record.opcode == 0xe4 && state.condition == saved) {
                state.pc.offset += record.bytes;
                return state;
            }
            if (record.opcode == 0xe5) {
                --state.condition;
                if (state.condition + 1 == saved) {
                    state.pc.offset += record.bytes;
                    return state;
                }
            }
            if (record.opcode == 0xa || record.opcode == 0xd) {
                state.condition = 0;
                return state;
            }
            state.pc.offset += record.bytes;
        }
        throw Failure{ScriptAdmission::work_limit, start};
    }

    void visit(State state) {
        const auto record = read(state.pc);
        const auto binding = detail::script_flow_binding(record.opcode, profile_);
        auto next = state;
        next.pc.offset += record.bytes;
        if (binding.context_dependent) {
            auto skipped = state;
            ++skipped.condition;
            enqueue(binding.opens_condition ? scan(skipped, true) : next);
        }
        switch (binding.flow) {
        case ScriptFlow::remember:
            next.saved = next.pc;
            break;
        case ScriptFlow::resume:
        case ScriptFlow::resume_yield:
            if (state.saved.block == UINT32_MAX)
                throw Failure{ScriptAdmission::unknown_continuation, state.pc, record.opcode};
            next.pc = state.saved;
            if (binding.flow == ScriptFlow::resume_yield) next.condition = 0;
            break;
        case ScriptFlow::next_block:
        case ScriptFlow::next_block_yield:
            next.pc = {++next.table_index, 0};
            if (binding.flow == ScriptFlow::next_block_yield) next.condition = 0;
            break;
        case ScriptFlow::skip: {
            next = state;
            const auto count = read_word(record.payload);
            if (count > scan_limit) throw Failure{ScriptAdmission::work_limit, state.pc, record.opcode};
            for (std::uint32_t i = 0; i < count; ++i) next.pc.offset += read(next.pc).bytes;
            break;
        }
        case ScriptFlow::delay:
            if (read_word(record.payload)) next.condition = 0;
            break;
        case ScriptFlow::if_test:
        case ScriptFlow::if_test_without_open: {
            if (record.opcode == 0x113 && read_word(record.payload) >= 4) break;
            if (binding.flow == ScriptFlow::if_test) ++state.condition;
            next.condition = state.condition;
            const bool can_fail = (record.opcode != 0x113 || read_word(record.payload.subspan(8)) < 6) &&
                (record.opcode != 0xea || std::to_integer<std::uint8_t>(record.payload[4]) <= 1);
            if (can_fail)
                enqueue(scan(state, true));
            if ((record.opcode == 0x17 && read_word(record.payload.subspan(4)) > 1) ||
                (record.opcode == 0x180 && read_word(record.payload) > 1)) return;
            break;
        }
        case ScriptFlow::else_scan:
            next = scan(state, false);
            break;
        case ScriptFlow::end_if:
            ++next.condition;
            break;
        case ScriptFlow::next:
            break;
        }
        enqueue(next);
    }

    DispatchProfile profile_;
    std::array<OpcodeCoverage, 432> coverage_;
    std::vector<std::span<const std::byte>> blocks_;
    std::vector<std::uint32_t> used_;
    std::set<State> seen_;
    std::deque<State> pending_;
};
}

ScriptProgram admit_script_program(const ScriptBank& bank, DispatchProfile profile) {
    ScriptProgram result;
    const std::uint32_t root = bank.format() == BankFormat::scenario_evb ? 0 : 8;
    for (std::size_t i = 0; i < result.entries.size(); ++i) {
        const auto block = root + std::uint32_t(i) * 4;
        if (bank.object(block)) result.entries[i] = Position{block, 0};
    }
    if (!result.entries[0] && !result.entries[1]) return result;
    try {
        result.program = Closure(bank, profile).build(result.entries);
        result.status = ScriptAdmission::admitted;
    } catch (const Failure& failure) {
        result.status = failure.status;
        result.failure = failure.at;
        result.opcode = failure.opcode;
    } catch (const std::invalid_argument&) {
        result.status = ScriptAdmission::invalid_payload;
    }
    return result;
}
}
