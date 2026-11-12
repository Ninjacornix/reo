#include "dialogue_records.hpp"
#include <algorithm>
#include <bit>
namespace reo::native::gameplay_world {
namespace {
std::int8_t byte(std::int32_t value)noexcept{return std::bit_cast<std::int8_t>(std::uint8_t(value));}
std::int16_t half(std::int32_t value)noexcept{return std::bit_cast<std::int16_t>(std::uint16_t(value));}
bool wide(std::byte value)noexcept{const auto c=std::to_integer<unsigned>(value);return (c>=0x80&&c<0xa0)||c>=0xe0;}
std::optional<std::size_t> line_start(std::span<const std::byte> body,std::int8_t line)noexcept{
    if(line<0)return{};
    std::size_t at{};
    for(unsigned current=0;current<unsigned(line);++current){while(at<body.size()&&body[at]!=std::byte{10})++at;if(at==body.size())return{};++at;}
    return at;
}
std::optional<std::span<const std::byte>> terminated(const std::array<std::byte,64>& buffer)noexcept{
    const auto end=std::find(buffer.begin(),buffer.end(),std::byte{});if(end==buffer.end())return{};
    return std::span<const std::byte>(buffer.data(),std::size_t(end-buffer.begin()));
}
}
DialogueReport advance_dialogue_record(DialogueRecord& record,std::uint8_t channel,const DialogueContext& context)noexcept{
    DialogueReport report;const auto fail=[&](DialogueStatus status){report.status=status;return report;};
    if(context.world.closed())return fail(DialogueStatus::closed);
    if(channel>=2)return fail(DialogueStatus::unsupported_profile);
    const auto text=record.text_owner?record.text_owner->text(record.text_index):std::nullopt;
    if(!text)return fail(DialogueStatus::unavailable);
    const auto body=text->body;const auto actor=context.world.resolve(record.actor);
    const auto erase=[&](){const auto value=terminated(record.buffer);return value&&context.presentation&&context.presentation->bound_to(context.world)&&context.presentation->erase(*value);};
    if(record.phase==0){
        report.stage=DialogueStage::initialize;record.phase=1;unsigned lines{};for(const auto value:body)lines+=value==std::byte{10};record.newlines=byte(std::int32_t(lines));record.page=0;
        if(!actor)return fail(DialogueStatus::unavailable);
        actor->speech.display_style=record.display_style;
    }
    if(record.phase==1){
        report.stage=DialogueStage::line;record.fade_ticks=8;record.alpha=0;record.phase=2;record.character_ticks=0;record.revealed=0;record.delay=record.initial_delay;record.buffer={};
        const auto begin=line_start(body,record.page);if(!begin)return fail(DialogueStatus::unsupported_profile);
        std::size_t end=*begin;while(end<body.size()&&body[end]!=std::byte{10}&&body[end]!=std::byte{13})++end;
        record.line_bytes=half(std::int32_t(end-*begin));record.center=half(320-5*std::int32_t(record.line_bytes));
        report.stage=DialogueStage::voice;bool request=channel==1||!context.previous_secondary_actor;
        if(!request){const auto previous=context.world.resolve(*context.previous_secondary_actor);if(!previous)return fail(DialogueStatus::unavailable);
            request=std::bit_cast<std::int16_t>(std::uint16_t(std::bit_cast<std::uint32_t>(previous->collision.basis.x.z)))>=0;}
        // The complete1BA250 negative-member path returns before any actor or
        // backend access, so this proven no-work leaf needs no stream binding.
        if(request&&record.voice>=0){
            if(!context.voice||!context.voice->bound_to(context.world))return fail(DialogueStatus::unavailable);
            const auto voice=context.voice->request(record.actor,record.voice);
            if(!gameplay_scenario::stream_accepted(voice.status))return fail(voice.status==gameplay_scenario::StreamStatus::busy?DialogueStatus::busy:DialogueStatus::unavailable);
        }
        report.stage=DialogueStage::corruption;record.corrupted={};record.glyphs=0;
        const int width=!body.empty()&&wide(body.front())?2:1;
        for(int consumed=0;consumed<record.line_bytes;consumed+=width)record.glyphs=half(record.glyphs+1);
        // The source repeatedly classifies the first body byte here. It does
        // not advance that pointer while counting the current line's bytes.
        if(record.glyphs>=3&&record.actor){
            if(!actor||!actor->speech.gauge_notice)return fail(DialogueStatus::unavailable);
            if(*actor->speech.gauge_notice){
                record.corruption_count=byte(std::int32_t(float(record.glyphs)*std::bit_cast<float>(0x3e99999au)));
                int remaining{};
                if(!record.literal)remaining=record.corruption_count+int(context.world.session().random.request(1)&1u);
                else record.corruption_count=0;
                if(remaining<0)return fail(DialogueStatus::unsupported_profile);
                while(remaining){const auto choice=unsigned(context.world.session().random.request(1))%unsigned(record.glyphs);if(!choice)continue;
                    if(choice>=record.corrupted.size())return fail(DialogueStatus::unsupported_profile);
                    --remaining;if(!record.corrupted[choice])record.corrupted[choice]=1;}
            }
        }
        record.reveal_index=0;
    }
    if(record.phase==2){
        report.stage=DialogueStage::fade;record.fade_ticks=byte(record.fade_ticks-1);
        if(record.fade_ticks<0){record.phase=3;record.fade_ticks=0;record.alpha=0x80;}
        else{record.alpha=std::uint8_t(record.alpha+0x10);if(record.alpha>0x80)record.alpha=0x80;}
    }else if(record.phase==3){
        report.stage=DialogueStage::fade;if(record.revealed>=record.line_bytes){record.delay=half(record.delay-1);if(record.delay<0){record.fade_ticks=8;record.phase=4;}}
    }else if(record.phase==4){
        report.stage=DialogueStage::fade;record.fade_ticks=byte(record.fade_ticks-1);
        if(record.fade_ticks<0){record.page=byte(record.page+1);
            if(record.page<record.newlines)record.phase=1;
            else{record.active=false;if(!actor)return fail(DialogueStatus::unavailable);actor->speech.display_style=0;}
            record.fade_ticks=0;record.alpha=0;report.stage=DialogueStage::erase;if(!erase())return fail(DialogueStatus::unavailable);report.stage=DialogueStage::completed;return report;
        }else{record.alpha=std::uint8_t(record.alpha-0x10);if(record.alpha>0x80)record.alpha=0;}
    }
    record.character_ticks=byte(record.character_ticks-1);const bool refresh=record.character_ticks<0;if(refresh)record.character_ticks=0;
    report.stage=DialogueStage::erase;if(!erase())return fail(DialogueStatus::unavailable);
    if(refresh){
    report.stage=DialogueStage::buffer;record.buffer={};std::copy(record.prefix.begin(),record.prefix.end(),record.buffer.begin());
    const auto body_byte=[&](std::size_t at)->std::optional<std::byte>{if(at<body.size())return body[at];if(at==body.size())return std::byte{};return{};};
    const auto glyph=[&](std::size_t at,int index)->std::optional<unsigned>{
        const auto first=body_byte(at);if(!first)return{};const unsigned bytes=wide(*first)?2:1;
        if(at>record.buffer.size()-4||bytes>record.buffer.size()-4-at)return{};
        if(bytes==2){if(index<0||unsigned(index)>=record.corrupted.size())return{};const auto second=body_byte(at+1);if(!second)return{};
            if(record.corrupted[unsigned(index)]){record.buffer[4+at]=std::byte{0x81};record.buffer[5+at]=std::byte{0x63};}
            else{record.buffer[4+at]=*first;record.buffer[5+at]=*second;}
        }else record.buffer[4+at]=*first;
        return bytes;
    };
    if(record.revealed<0)return fail(DialogueStatus::unsupported_profile);
    if(record.literal){const auto count=std::size_t(record.revealed);if(count>body.size()||count>record.buffer.size()-4)return fail(DialogueStatus::unsupported_profile);std::copy_n(body.begin(),count,record.buffer.begin()+4);}
    else{std::size_t at{};int index{};while(at<std::size_t(record.revealed)){const auto bytes=glyph(at,index);if(!bytes)return fail(DialogueStatus::unsupported_profile);at+=*bytes;++index;}}
    if(record.revealed<record.line_bytes){const auto bytes=glyph(std::size_t(record.revealed),record.reveal_index);if(!bytes)return fail(DialogueStatus::unsupported_profile);record.revealed=half(record.revealed+std::int32_t(*bytes));record.reveal_index=byte(record.reveal_index+1);}
    }
    report.stage=DialogueStage::visibility;const auto hidden=context.presentation->suppressed();if(!hidden)return fail(DialogueStatus::unavailable);
    if(!*hidden){report.stage=DialogueStage::draw;const auto value=terminated(record.buffer);if(!value)return fail(DialogueStatus::unsupported_profile);if(!context.presentation->draw(record.center,channel?346:320,*value,record.alpha))return fail(DialogueStatus::unavailable);}
    if(record.delay<30&&context.selected_counts[channel]>=2&&context.second_selected_active[channel])record.delay=0;
    report.stage=DialogueStage::completed;return report;
}
} // namespace reo::native::gameplay_world
