#include "queue.hpp"
#include <bit>
#include <climits>
#include <stdexcept>
#include <utility>

namespace reo::native::lsc_queue {
std::shared_ptr<const Name> Name::prepare(std::string_view value) {
    if (value.size() > maximum_name_bytes || value.find('\0') != value.npos)
        throw std::invalid_argument("Bounded immutable filename required");
    return std::shared_ptr<const Name>(new Name(value));
}
Queue::Queue(Config c, std::shared_ptr<LowerFile> file,
             std::shared_ptr<EmptyNotification> notification, std::shared_ptr<Errors> errors)
    : file_(std::move(file)), notification_(std::move(notification)), errors_(std::move(errors)),
      minimum_(c.capacity_bytes * 8 / 10), capacity_(c.capacity_bytes), tail_(c.initial_slot), head_(c.initial_slot) {
    if (!file_ || !notification_ || !errors_ || c.capacity_bytes > INT_MAX / 8 ||
        c.initial_slot >= slots || c.previous_sequence > INT_MAX)
        throw std::invalid_argument("LSC queue admission");
    records_[(tail_ + slots - 1) % slots].sequence = c.previous_sequence;
}
std::int32_t Queue::enqueue(Entry entry) noexcept {
    if (count_ == slots) return -1;
    if (!entry.name) { errors_->report(Error::invalid_argument); return -1; }
    const auto previous = records_[(tail_ + slots - 1) % slots].sequence;
    auto& record = records_[tail_];
    record.sequence = previous == INT_MAX ? 0 : previous + 1;
    record.entry = std::move(entry); record.checksum = 0;
    for (const auto byte : record.entry.name->bytes()) record.checksum += static_cast<unsigned char>(byte);
    record.status = record.progress = 0;
    tail_ = (tail_ + 1) % slots; ++count_;
    if (state_ == 1) state_ = 2;
    return static_cast<std::int32_t>(record.sequence);
}
void Queue::clear() noexcept { if (!state_) count_ = tail_ = head_ = 0; }
void Queue::start() noexcept { if (state_) stop(); state_ = count_ ? 2 : 1; }
void Queue::stop() noexcept {
    if (!state_) return;
    state_ = 0;
    if (file_->present() && transferring_ == 1) { file_->stop_async(); transferring_ = 0; }
    limit_ = 0; clear(); extra_ = 0;
}
void Queue::pause(std::int32_t argument) noexcept { paused_ = argument == 1 ? 1 : 0; }
void Queue::repeat(std::int32_t argument) noexcept { repeat_ = static_cast<std::uint8_t>(argument); }
void Queue::minimum(std::int32_t argument) noexcept {
    if (argument < 0 || static_cast<std::uint32_t>(argument) > capacity_) { errors_->report(Error::invalid_minimum); return; }
    minimum_ = static_cast<std::uint32_t>(argument);
}
const Record* Queue::find(std::uint32_t sequence) noexcept {
    for (const auto& record : records_) if (record.sequence == sequence) return &record;
    errors_->report(Error::missing_sequence); return nullptr;
}
std::int32_t Queue::ordinal(std::int32_t ordinal) noexcept {
    if (ordinal < 0 || static_cast<std::uint32_t>(ordinal) >= count_) { errors_->report(Error::invalid_ordinal); return -1; }
    return std::bit_cast<std::int32_t>(records_[(head_ + ordinal) % slots].sequence);
}
std::shared_ptr<const Name> Queue::name(std::uint32_t sequence) noexcept {
    const auto* record = find(sequence); return record ? record->entry.name : nullptr;
}
std::int32_t Queue::status(std::uint32_t sequence) noexcept {
    const auto* record = find(sequence); return record ? std::bit_cast<std::int32_t>(record->status) : -1;
}
std::uint32_t Queue::progress(std::uint32_t sequence) noexcept {
    const auto* record = find(sequence); return record ? record->progress : 0;
}
void Queue::start_head() noexcept {
    if (!count_) return;
    auto& record = records_[head_];
    file_->stop_before_open(); file_->close_before_open();
    // Names are sealed copies: borrowed-name checksum mutation is inadmissible.
    file_->open_range(record.entry); file_->set_limit(record.entry.range.sectors);
    limit_ = record.entry.range.sectors; record.progress = 0; transferring_ = 0;
    file_->thresholds(minimum_, capacity_); file_->position(0); file_->start();
    transferring_ = 1; record.status = 1;
}
void Queue::poll_head() noexcept {
    if (!file_->present()) { errors_->report(Error::missing_file); return; }
    auto& record = records_[head_];
    switch (file_->state()) {
    case 4: state_ = 3; break;
    case 2: record.progress = file_->progress_sectors(); break;
    case 3: record.status = 2; record.progress = limit_; break;
    default: break;
    }
}
void Queue::retire_head() noexcept {
    if (!file_->present()) return;
    Entry retained;
    if (repeat_ == 1) retained = records_[head_].entry;
    head_ = (head_ + 1) % slots; --count_;
    if (!count_) { notification_->notify(); state_ = 1; }
    if (repeat_ == 1) (void)enqueue(std::move(retained));
}
Service Queue::service() noexcept {
    if (servicing_) return Service::busy;
    if (paused_ == 1 || state_ != 2 || !count_) return Service::completed;
    servicing_ = true; struct Exit { bool& value; ~Exit() { value = false; } } exit{servicing_};
    if (records_[head_].status == 1) poll_head();
    if (records_[head_].status == 2) retire_head();
    if (records_[head_].status == 0) start_head();
    return Service::completed;
}
Snapshot Queue::snapshot() const noexcept {
    return {records_, state_, transferring_, repeat_, paused_, minimum_, capacity_, tail_, head_, count_, limit_, extra_, file_->present(), servicing_};
}
}
