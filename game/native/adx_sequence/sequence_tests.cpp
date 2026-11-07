#include "sequence.hpp"
#include "../adxt_shared_player/test_sources.hpp"
#include <array>
#include <cstdio>
#include <stdexcept>

namespace q = reo::native::adx_sequence;
namespace f = reo::native::adxt_shared_player::testing;
namespace r = reo::native::resources;
unsigned checks{};
void check(bool value) { ++checks; if (!value) throw std::runtime_error("Sequence check " + std::to_string(checks)); }
std::shared_ptr<f::File> file(unsigned channels, unsigned rate, unsigned total) {
    auto value = f::file(channels, rate, total);
    const auto end = 96 + (total + 31) / 32 * 18 * channels;
    value->bytes.resize((end + 18 + 2047) / 2048 * 2048);
    f::be16(value->bytes, end, 0x8001); f::be16(value->bytes, end + 2, 14);
    return value;
}
struct Large final : r::ByteView {
    mutable unsigned reads{};
    std::uint64_t size() const noexcept override { return 0xfffffffffffff800ull; }
    r::ReadResult read(std::uint64_t, std::span<std::byte>) const override { ++reads; return {}; }
};
int main() { try {
    for (unsigned channels : {1u, 2u}) for (unsigned rate : {24000u, 44100u, 48000u})
        for (unsigned total : {1u, 31u, 33u, 20000u}) {
            auto left = file(channels, rate, total), right = file(channels, rate, 4097);
            std::array<std::shared_ptr<const r::ByteView>, 2> views{left, right};
            const auto result = q::Sequence::prepare(views); check(result.status == q::Status::completed);
            const auto& sequence = *result.sequence;
            check(sequence.total_samples() == total + 4097 && sequence.frequency() == rate && sequence.channels() == channels);
            check(sequence.size() == left->size() + right->size() && sequence.segments()[1].sample_offset == total);
            std::array<std::byte, 64> bytes{};
            check(sequence.read(left->size() - 32, bytes) == r::ReadResult{r::Status::ok, bytes.size()});
            for (unsigned i = 0; i < 32; ++i) check(bytes[i] == std::byte(left->bytes[left->bytes.size() - 32 + i]) && bytes[32 + i] == std::byte(right->bytes[i]));
            bytes.fill(std::byte{0xa5});
            check(sequence.read(sequence.size() - 31, bytes).status == r::Status::invalid_range && bytes[0] == std::byte{0xa5});
            check(sequence.read(sequence.size(), {}) == r::ReadResult{r::Status::ok, 0});
        }
    auto one = file(1, 48000, 8193); auto two = file(1, 48000, 64);
    auto clip = q::Clip::prepare(two); check(clip.status == q::Status::completed);
    check(clip.clip->metadata().view == two && clip.clip->metadata().header.output_channels == 1 &&
          clip.clip->metadata().header.base.total_samples == 64 && clip.clip->metadata().encoded_end == 132);
    auto loop = file(1, 48000, 64); f::be16(loop->bytes, 22, 1);
    check(q::Clip::prepare(loop).status == q::Status::unsupported_header);
    check(q::Clip::prepare({}).status == q::Status::invalid_input);
    auto ainf=file(1,48000,12000);f::be32(ainf->bytes,24,0x41494e46);f::be32(ainf->bytes,28,1);
    f::be16(ainf->bytes,48,0xffff);f::be16(ainf->bytes,52,0xff80);f::be16(ainf->bytes,54,0xff80);
    check(q::Clip::prepare(ainf).status==q::Status::incompatible_output);
    std::array<std::shared_ptr<const r::ByteView>,2> inadmissible{ainf,two};
    check(q::Sequence::prepare(inadmissible).status==q::Status::incompatible_output);
    f::be16(ainf->bytes,48,0);check(q::Clip::prepare(ainf).status==q::Status::completed);
    std::array<std::shared_ptr<const r::ByteView>, 2> views{one, two};
    auto result = q::Sequence::prepare(views); check(result.status == q::Status::completed);
    std::weak_ptr<const f::File> retained = one; views = {}; one.reset();
    check(!retained.expired()); result.sequence.reset(); check(retained.expired());
    auto invalid = file(1, 48000, 100); invalid->bytes.back() = 1;
    views = {two, invalid}; check(q::Sequence::prepare(views).status == q::Status::unsupported_header);
    views = {two, file(2, 48000, 100)}; check(q::Sequence::prepare(views).status == q::Status::incompatible_output);
    views = {two, file(1, 24000, 100)}; check(q::Sequence::prepare(views).status == q::Status::incompatible_output);
    auto large = std::make_shared<Large>(); views = {large, two};
    check(q::Sequence::prepare(views).status == q::Status::numeric_limit && !large->reads);
    views = {two, {}}; check(q::Sequence::prepare(views).status == q::Status::invalid_input);
    check(q::Sequence::prepare(std::span(views).first(1)).status == q::Status::invalid_input);
    std::array<std::shared_ptr<const r::ByteView>, 17> many; many.fill(two);
    check(q::Sequence::prepare(many).status == q::Status::invalid_input);
    std::printf("%u immutable ADX sequence checks\n", checks);
} catch (const std::exception& e) { std::fprintf(stderr, "%s\n", e.what()); return 1; } }
