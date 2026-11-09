#include "contact_content.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_collision::delivery {
struct Catalog::Data {
    Tables tables;
    std::array<std::vector<std::shared_ptr<const Definition>>, 3> banks;
};
namespace {
class Reader {
  public:
    explicit Reader(std::span<const std::byte> bytes) : bytes_(bytes) {}
    std::uint8_t byte() {
        if (at_ == bytes_.size())
            fail();
        return std::to_integer<std::uint8_t>(bytes_[at_++]);
    }
    std::uint16_t half() {
        const auto low = byte();
        return std::uint16_t(low | (std::uint16_t(byte()) << 8));
    }
    std::uint32_t word() {
        const auto low = half();
        return std::uint32_t(low) | (std::uint32_t(half()) << 16);
    }
    std::int16_t signed_half() {
        return std::bit_cast<std::int16_t>(half());
    }
    float real() {
        return std::bit_cast<float>(word());
    }
    float finite() {
        const auto value = real();
        if (!std::isfinite(value))
            fail();
        return value;
    }
    Vec3 point() {
        return {finite(), finite(), finite()};
    }
    std::optional<std::uint16_t> joint() {
        const auto index = half();
        return index == 65535 ? std::optional<std::uint16_t>{} : index;
    }
    Value value() {
        return {signed_half(), byte()};
    }
    DistanceValues bins() {
        DistanceValues result;
        for (auto& bin : result.bins)
            bin = value();
        return result;
    }
    Template response() {
        Template t;
        t.base = signed_half();
        t.route_amount = signed_half();
        t.damage_kind = byte();
        t.priority = byte();
        t.auxiliary_a = byte();
        t.auxiliary_b = byte();
        t.max_contacts = byte();
        t.cooldown = byte();
        t.flags = byte();
        t.actor_sound = byte();
        t.kind = byte();
        t.response_code = byte();
        t.value_id = byte();
        t.query_flags = byte();
        t.response_flags = byte();
        t.progression = byte();
        t.scene_sound = byte();
        t.probability = byte();
        return t;
    }
    Definition definition() {
        Definition d;
        d.startup = byte();
        d.lifetime = byte();
        d.mask = byte();
        d.attachment_flags = byte();
        d.key = byte();
        d.response = response();
        const auto kind = byte();
        if (kind == 0) {
            if (d.lifetime)
                fail();
        } else if (kind == 1) {
            SegmentShape g;
            g.origin = point();
            g.direction = point();
            g.range = half();
            g.joint = joint();
            d.geometry = g;
        } else if (kind == 2) {
            SweepShape g;
            g.center = point();
            g.radius = half();
            g.joint = joint();
            d.geometry = g;
        } else if (kind == 3) {
            MarginShape g;
            g.origin = point();
            g.direction = point();
            g.margin = half();
            g.range = half();
            g.joint = joint();
            d.geometry = g;
        } else if (kind == 4) {
            AngularShape g;
            g.origin = point();
            g.direction = point();
            g.extent = half();
            g.range = half();
            g.joint = joint();
            d.geometry = g;
        } else
            fail();
        return d;
    }
    void finish() {
        if (at_ != bytes_.size())
            fail();
    }
    [[noreturn]] static void fail() {
        throw std::invalid_argument("Invalid converted native contact content");
    }

  private:
    std::span<const std::byte> bytes_;
    std::size_t at_{};
};
} // namespace
Catalog Catalog::import(std::span<const std::byte> bytes) {
    Reader input(bytes);
    for (const auto expected : std::array<std::uint8_t, 8>{'R', 'E', 'O', 'C', 'N', 'T', '0', '1'})
        if (input.byte() != expected)
            Reader::fail();
    if (input.word() != 1)
        Reader::fail();
    const auto categories = input.word(), rows = input.word();
    if (categories > 256 || rows > 65536)
        Reader::fail();
    std::array<std::uint32_t, 3> bank_counts;
    for (auto& count : bank_counts) {
        count = input.word();
        if (count > 65536)
            Reader::fail();
    }
    auto next = std::make_shared<Data>();
    for (auto& probability : next->tables.probabilities)
        probability = input.real();
    for (auto& weight : next->tables.weights)
        weight = input.signed_half();
    next->tables.flat.emplace();
    for (auto& value : *next->tables.flat)
        value = input.bins();
    for (unsigned i = 0; i < categories; ++i) {
        auto& category = next->tables.categories[i];
        const auto kind = input.byte();
        if (kind > 1)
            Reader::fail();
        category.admitted = true;
        if (kind) {
            category.entries.emplace();
            for (auto& value : *category.entries)
                value = input.bins();
        }
    }
    for (unsigned i = 0; i < rows; ++i) {
        const auto key = input.signed_half();
        RandomValues values;
        for (auto& difficulty : values.damage)
            for (auto& value : difficulty)
                value = input.half();
        for (auto& difficulty : values.progression)
            for (auto& value : difficulty)
                value = input.half();
        if (!next->tables.random.emplace(key, values).second)
            Reader::fail();
    }
    for (unsigned bank = 0; bank < 3; ++bank) {
        auto& entries = next->banks[bank];
        entries.reserve(bank_counts[bank]);
        for (unsigned i = 0; i < bank_counts[bank]; ++i)
            entries.push_back(std::make_shared<const Definition>(input.definition()));
    }
    input.finish();
    Catalog result;
    result.data_ = std::move(next);
    return result;
}
std::shared_ptr<const Definition> Catalog::find(std::uint8_t bank,
                                                std::int32_t ordinal) const noexcept {
    if (!data_ || bank >= data_->banks.size() || ordinal < 0 ||
        std::size_t(ordinal) >= data_->banks[bank].size())
        return {};
    return data_->banks[bank][std::size_t(ordinal)];
}
std::size_t Catalog::size(std::uint8_t bank) const noexcept {
    return data_ && bank < data_->banks.size() ? data_->banks[bank].size() : 0;
}
const Tables& Catalog::tables() const {
    if (!data_)
        throw std::logic_error("Native contact catalog is absent");
    return data_->tables;
}
} // namespace reo::native::gameplay_collision::delivery
