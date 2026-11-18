// Recovered offline from complete owned File1 player event bodies.
// Native typed selector branches; no guest instruction or address execution.
void common_tail(Context& ctx, std::uint16_t selector) {
    switch (selector) {
    case 216:
    case 753:
    case 761:
    case 762:
    case 863:
        ctx.emit(Event{EventKind::surface_pair_one, 10, 0u, 0u, 0u});
        return;
    case 217:
        ctx.emit(Event{EventKind::surface_pair_one, 23, 0u, 0u, 0u});
        return;
    case 242:
        ctx.emit(Event{EventKind::model_action, 26, 0u, 12u, 1u});
        return;
    case 243:
        ctx.emit(Event{EventKind::actor_audio, 0, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::contact_action, 10, 0u, 122u, 0u});
        return;
    case 245:
        ctx.emit(Event{EventKind::surface_pair_one, 34, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 66, 0u, 0u, 0u});
        return;
    case 246:
        ctx.emit(Event{EventKind::surface_pair_one, 36, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 74, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 110, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 162, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 20, 0u, 21u, 0u});
        ctx.emit(Event{EventKind::contact_action, 20, 0u, 201u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 42, 0u, 21u, 0u});
        ctx.emit(Event{EventKind::contact_action, 42, 0u, 202u, 0u});
        return;
    case 352:
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 54, 0u, 0u, 0u});
        return;
    case 353:
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 46, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 140, 0u, 0u, 0u});
        return;
    case 354:
    case 755:
    case 856:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        return;
    case 356:
        ctx.emit(Event{EventKind::surface_pair_one, 8, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 18, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 33, 0u, 0u, 0u});
        return;
    case 361:
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 34, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 54, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 82, 0u, 0u, 0u});
        return;
    case 365:
        ctx.emit(Event{EventKind::surface_pair_one, 35, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 288, 0u, 0u, 0u});
        return;
    case 366:
        ctx.emit(Event{EventKind::surface_pair_one, 34, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 230, 0u, 0u, 0u});
        return;
    case 389:
    case 446:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 36, 0u, 0u, 0u});
        return;
    case 390:
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 40, 0u, 0u, 0u});
        return;
    case 437:
        ctx.emit(Event{EventKind::surface_pair_one, 8, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 23, 0u, 0u, 0u});
        return;
    case 440:
        ctx.emit(Event{EventKind::surface_pair_one, 12, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 32, 0u, 0u, 0u});
        return;
    case 445:
        ctx.emit(Event{EventKind::surface_pair_one, 32, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 46, 0u, 0u, 0u});
        return;
    case 500:
        ctx.emit(Event{EventKind::surface_pair_one, 2, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 34, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 37, 0u, 0u, 0u});
        return;
    case 742:
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 34, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 88, 2u, 0u, 0u});
        return;
    case 743:
        ctx.emit(Event{EventKind::surface_pair_one, 28, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 48, 0u, 0u, 0u});
        return;
    case 744:
        ctx.emit(Event{EventKind::surface_pair_one, 21, 0u, 0u, 0u});
        return;
    case 745:
        ctx.emit(Event{EventKind::surface_pair_one, 218, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 96, 0u, 6u, 0u});
        return;
    case 746:
        ctx.emit(Event{EventKind::surface_pair_one, 62, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 155, 0u, 0u, 0u});
        return;
    case 747:
        ctx.emit(Event{EventKind::surface_pair_one, 70, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 166, 0u, 0u, 0u});
        return;
    case 748:
        ctx.emit(Event{EventKind::surface_pair_one, 86, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 172, 0u, 0u, 0u});
        return;
    case 749:
        ctx.emit(Event{EventKind::surface_pair_one, 70, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 150, 0u, 0u, 0u});
        return;
    case 750:
        ctx.emit(Event{EventKind::surface_pair_one, 0, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 65, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 140, 0u, 0u, 0u});
        return;
    case 751:
        ctx.emit(Event{EventKind::surface_pair_one, 90, 0u, 0u, 0u});
        return;
    case 752:
        ctx.emit(Event{EventKind::surface_pair_one, 32, 0u, 0u, 0u});
        return;
    case 754:
        ctx.emit(Event{EventKind::surface_pair_one, 26, 0u, 0u, 0u});
        return;
    case 757:
        ctx.emit(Event{EventKind::surface_pair_one, 78, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 136, 0u, 0u, 0u});
        return;
    case 758:
        ctx.emit(Event{EventKind::surface_pair_one, 18, 0u, 0u, 0u});
        return;
    case 759:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        return;
    case 760:
        ctx.emit(Event{EventKind::surface_pair_one, 15, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        return;
    case 766:
        ctx.emit(Event{EventKind::surface_pair_one, 54, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 60, 0u, 0u, 0u});
        return;
    case 767:
        ctx.emit(Event{EventKind::actor_audio, 130, 0u, 6u, 0u});
        return;
    case 792:
        ctx.emit(Event{EventKind::surface_pair_one, 72, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 96, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 125, 0u, 0u, 0u});
        return;
    case 793:
        ctx.emit(Event{EventKind::surface_pair_one, 60, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 63, 0u, 0u, 0u});
        return;
    case 843:
        ctx.emit(Event{EventKind::surface_pair_one, 0, 2u, 0u, 0u});
        return;
    case 850:
        ctx.emit(Event{EventKind::position_audio, 32, 65u, 0u, 0u});
        return;
    case 853:
    case 855:
        ctx.emit(Event{EventKind::surface_pair_one, 25, 0u, 0u, 0u});
        return;
    case 859:
        ctx.emit(Event{EventKind::surface_pair_one, 28, 0u, 0u, 0u});
        return;
    case 917:
        ctx.emit(Event{EventKind::position_audio, 0, 61u, 0u, 0u});
        return;
    case 926:
        ctx.emit(Event{EventKind::surface_pair_one, 6, 0u, 0u, 0u});
        return;
    default:
        return;
    }
}

void lower_zero(Context& ctx, std::uint16_t selector) {
    switch (selector) {
    case 160:
    case 161:
        ctx.emit(Event{EventKind::surface_pair_zero, 14, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_zero, 46, 0u, 0u, 0u});
        return;
    case 162:
    case 163:
        ctx.emit(Event{EventKind::surface_pair_zero, 24, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_zero, 52, 0u, 0u, 0u});
        return;
    case 164:
        ctx.emit(Event{EventKind::surface_pair_zero, 18, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_zero, 50, 0u, 0u, 0u});
        return;
    case 165:
        ctx.emit(Event{EventKind::surface_pair_zero, 40, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_zero, 70, 0u, 0u, 0u});
        return;
    case 166:
        ctx.emit(Event{EventKind::surface_pair_zero, 30, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_zero, 62, 0u, 0u, 0u});
        return;
    case 167:
        ctx.emit(Event{EventKind::surface_pair_zero, 36, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_zero, 64, 0u, 0u, 0u});
        return;
    case 175:
        ctx.emit(Event{EventKind::surface_pair_zero, 1, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_zero, 31, 0u, 0u, 0u});
        return;
    case 176:
        ctx.emit(Event{EventKind::surface_pair_zero, 25, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_zero, 65, 0u, 0u, 0u});
        return;
    case 378:
        ctx.emit(Event{EventKind::surface_pair_zero, 18, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_zero, 36, 0u, 0u, 0u});
        return;
    case 379:
        ctx.emit(Event{EventKind::surface_pair_zero, 4, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_zero, 10, 0u, 0u, 0u});
        return;
    default:
        return;
    }
}

void lower_one(Context& ctx, std::uint16_t selector) {
    switch (selector) {
    case 160:
        ctx.emit(Event{EventKind::surface_pair_zero, 38, 0u, 0u, 0u});
        return;
    case 161:
    case 163:
        ctx.emit(Event{EventKind::surface_pair_zero, 40, 0u, 0u, 0u});
        return;
    case 162:
    case 165:
        ctx.emit(Event{EventKind::surface_pair_zero, 34, 0u, 0u, 0u});
        return;
    case 164:
        ctx.emit(Event{EventKind::surface_pair_zero, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_zero, 68, 0u, 0u, 0u});
        return;
    case 166:
        ctx.emit(Event{EventKind::surface_pair_zero, 30, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_zero, 66, 0u, 0u, 0u});
        return;
    case 167:
        ctx.emit(Event{EventKind::surface_pair_zero, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_zero, 62, 0u, 0u, 0u});
        return;
    case 175:
        ctx.emit(Event{EventKind::surface_pair_zero, 1, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_zero, 31, 0u, 0u, 0u});
        return;
    case 176:
        ctx.emit(Event{EventKind::surface_pair_zero, 25, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_zero, 67, 0u, 0u, 0u});
        return;
    case 191:
        ctx.emit(Event{EventKind::surface_pair_zero, 44, 0u, 0u, 0u});
        return;
    case 192:
        ctx.emit(Event{EventKind::surface_pair_zero, 46, 0u, 0u, 0u});
        return;
    case 378:
        ctx.emit(Event{EventKind::surface_pair_zero, 20, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_zero, 32, 0u, 0u, 0u});
        return;
    case 379:
        ctx.emit(Event{EventKind::surface_pair_zero, 18, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_zero, 38, 0u, 0u, 0u});
        return;
    default:
        return;
    }
}

void upper_zero(Context& ctx, std::uint16_t selector) {
    switch (selector) {
    case 101:
        ctx.emit(Event{EventKind::surface_pair_one, 26, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 70, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 116, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 26, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 70, 6u, 130u, 0u});
        ctx.emit(Event{EventKind::model_action, 116, 6u, 129u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 102:
        ctx.emit(Event{EventKind::surface_pair_one, 28, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 70, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 114, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 160, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 28, 6u, 65u, 0u});
        ctx.emit(Event{EventKind::model_action, 70, 6u, 66u, 0u});
        ctx.emit(Event{EventKind::model_action, 114, 6u, 65u, 0u});
        ctx.emit(Event{EventKind::model_action, 160, 6u, 66u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 103:
        ctx.emit(Event{EventKind::surface_pair_one, 26, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 60, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 96, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 130, 0u, 0u, 0u});
        if (ctx.actor.category == 0) {
            ctx.emit(Event{EventKind::actor_audio, 88, 2u, 8u, 0u});
            ctx.emit(Event{EventKind::model_action, 26, 6u, 129u, 0u});
            ctx.emit(Event{EventKind::model_action, 60, 6u, 130u, 0u});
            ctx.emit(Event{EventKind::model_action, 96, 6u, 129u, 0u});
            ctx.emit(Event{EventKind::model_action, 130, 6u, 130u, 0u});
            common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        } else {
            ctx.emit(Event{EventKind::alternate_audio, 88, 0u, 5u, 0u});
            ctx.emit(Event{EventKind::model_action, 26, 6u, 129u, 0u});
            ctx.emit(Event{EventKind::model_action, 60, 6u, 130u, 0u});
            ctx.emit(Event{EventKind::model_action, 96, 6u, 129u, 0u});
            ctx.emit(Event{EventKind::model_action, 130, 6u, 130u, 0u});
            common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        }
        return;
    case 104:
        ctx.emit(Event{EventKind::surface_pair_one, 8, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 124:
        ctx.emit(Event{EventKind::surface_pair_one, 28, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 86, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 28, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 86, 6u, 130u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 125:
        ctx.emit(Event{EventKind::surface_pair_one, 26, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 50, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 26, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 50, 6u, 130u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 126:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 60, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 102, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 150, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 16, 6u, 65u, 0u});
        ctx.emit(Event{EventKind::model_action, 60, 6u, 66u, 0u});
        ctx.emit(Event{EventKind::model_action, 102, 6u, 65u, 0u});
        ctx.emit(Event{EventKind::model_action, 150, 6u, 66u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 127:
        ctx.emit(Event{EventKind::surface_pair_one, 0, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 131:
        ctx.emit(Event{EventKind::actor_audio, 64, 2u, 10u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 132:
        ctx.emit(Event{EventKind::actor_audio, 28, 2u, 10u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 133:
        ctx.emit(Event{EventKind::surface_pair_one, 10, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 134:
    case 213:
    case 227:
    case 269:
        ctx.emit(Event{EventKind::surface_pair_one, 12, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 135:
        ctx.emit(Event{EventKind::surface_pair_one, 26, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 82, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 60, 3u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 92, 2u, 10u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 104, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 136:
        ctx.emit(Event{EventKind::surface_pair_one, 42, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 44, 3u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 112, 2u, 10u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 137:
        ctx.emit(Event{EventKind::surface_pair_one, 48, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 76, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 108, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 88, 3u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 126, 2u, 8u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 138:
    case 139:
        ctx.emit(Event{EventKind::surface_pair_one, 40, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 50, 2u, 10u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 141:
        ctx.emit(Event{EventKind::surface_pair_one, 10, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 142:
        ctx.emit(Event{EventKind::surface_pair_one, 80, 3u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 54, 2u, 10u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 143:
        ctx.emit(Event{EventKind::surface_pair_one, 8, 3u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 10, 2u, 10u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 146:
        ctx.emit(Event{EventKind::surface_pair_one, 42, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 76, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 149:
        ctx.emit(Event{EventKind::surface_pair_one, 32, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 50, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 151:
        ctx.emit(Event{EventKind::surface_pair_one, 76, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 128, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 151, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 153:
        ctx.emit(Event{EventKind::surface_pair_one, 92, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 186, 2u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 154:
        ctx.emit(Event{EventKind::model_action, 126, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 48, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 94, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 126, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 169:
        ctx.emit(Event{EventKind::surface_pair_one, 8, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 98, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 126, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 170:
        ctx.emit(Event{EventKind::surface_pair_one, 18, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 48, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 156, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 168, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 172:
        ctx.emit(Event{EventKind::surface_pair_one, 29, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 50, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 173:
        ctx.emit(Event{EventKind::surface_pair_one, 39, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 72, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 113, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 150, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 174:
        ctx.emit(Event{EventKind::surface_pair_one, 12, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 70, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 104, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 141, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 177:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 38, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 122, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 140, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 178:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 46, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 152, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 170, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 185:
        ctx.emit(Event{EventKind::surface_pair_one, 10, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 42, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 186:
        ctx.emit(Event{EventKind::surface_pair_one, 200, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 248, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 188:
        ctx.emit(Event{EventKind::surface_pair_one, 44, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 189:
        ctx.emit(Event{EventKind::surface_pair_one, 6, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 51, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 84, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 134, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 190:
        ctx.emit(Event{EventKind::surface_pair_one, 55, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 82, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 134, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 163, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 191:
        ctx.emit(Event{EventKind::surface_pair_one, 46, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 192:
        ctx.emit(Event{EventKind::surface_pair_one, 50, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 193:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 94, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 194:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 134, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 215:
        ctx.emit(Event{EventKind::surface_pair_one, 12, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 18, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 18, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 231:
        ctx.emit(Event{EventKind::surface_pair_one, 2, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 41, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 73, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 116, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 190, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 232:
        ctx.emit(Event{EventKind::surface_pair_one, 0, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 104, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 133, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 165, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 196, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 233:
        ctx.emit(Event{EventKind::actor_audio, 10, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 42, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 10, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 24, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 235:
        ctx.emit(Event{EventKind::surface_pair_one, 13, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 31, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 236:
        ctx.emit(Event{EventKind::surface_pair_one, 40, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 60, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 237:
        ctx.emit(Event{EventKind::surface_pair_one, 28, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 30, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 54, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 252:
    case 253:
        ctx.emit(Event{EventKind::contact_action, 18, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 18, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 264:
    case 265:
    case 266:
        ctx.emit(Event{EventKind::resource_audio, 14, 0u, 1u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 14, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::contact_action, 14, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 22, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 268:
    case 410:
    case 425:
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 270:
    case 271:
    case 272:
        ctx.emit(Event{EventKind::resource_audio, 0, 0u, 17u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 277:
    case 279:
        ctx.emit(Event{EventKind::resource_audio, 14, 0u, 1u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 14, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::contact_action, 14, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 18, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 278:
        ctx.emit(Event{EventKind::resource_audio, 14, 0u, 1u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 14, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::contact_action, 16, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 20, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 281:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 42, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 282:
        ctx.emit(Event{EventKind::surface_pair_one, 28, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 48, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 286:
        ctx.emit(Event{EventKind::surface_pair_one, 58, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 18, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::contact_action, 16, 0u, 126u, 0u});
        ctx.emit(Event{EventKind::contact_action, 22, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 340:
        ctx.emit(Event{EventKind::surface_pair_one, 42, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 84, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 122, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 341:
        ctx.emit(Event{EventKind::surface_pair_one, 60, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 84, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 106, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 138, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 342:
        ctx.emit(Event{EventKind::surface_pair_one, 84, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 110, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 138, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 178, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 343:
        ctx.emit(Event{EventKind::surface_pair_one, 40, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 92, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 112, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 132, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 158, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 184, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 344:
    case 345:
    case 348:
    case 349:
        ctx.emit(Event{EventKind::node_audio, 36, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 346:
    case 347:
        if (ctx.actor.motion_class == 0x39) {
            ctx.emit(Event{EventKind::contact_action, 1, 0u, 200u, 0u});
            ctx.emit(Event{EventKind::contact_action, 100, 3u, 0u, 0u});
            common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        } else {
            common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        }
        return;
    case 352:
        ctx.emit(Event{EventKind::surface_pair_one, 18, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 357:
        ctx.emit(Event{EventKind::surface_pair_one, 28, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 36, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 361:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 32, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 54, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 370:
    case 381:
        ctx.emit(Event{EventKind::surface_pair_one, 8, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 372:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 397:
        ctx.emit(Event{EventKind::resource_audio, 30, 0u, 4u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 32, 0u, 4u, 0u});
        ctx.emit(Event{EventKind::resource_program, 0, 2u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 398:
        ctx.emit(Event{EventKind::resource_audio, 10, 0u, 2u, 0u});
        ctx.emit(Event{EventKind::resource_program, 0, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 401:
        ctx.emit(Event{EventKind::resource_audio, 16, 0u, 25u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 402:
        ctx.emit(Event{EventKind::resource_callback, 0, 0u, 0u, 0u});
        if ((ctx.metadata.action_flags(ctx.actor.resource_action) & 0x20) != 0) {
            ctx.emit(Event{EventKind::resource_audio, 10, 0u, 7u, 0u});
            ctx.emit(Event{EventKind::resource_audio, 50, 0u, 2u, 0u});
            common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        } else {
            common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        }
        return;
    case 403:
        ctx.emit(Event{EventKind::resource_audio, 10, 0u, 24u, 0u});
        ctx.emit(Event{EventKind::resource_program, 34, 5u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 412:
    case 415:
    case 417:
        ctx.emit(Event{EventKind::model_action, 40, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 40, 0u, 6u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 413:
        ctx.emit(Event{EventKind::surface_pair_one, 8, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 28, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 418:
        ctx.emit(Event{EventKind::surface_pair_one, 32, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 48, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 419:
    case 601:
        ctx.emit(Event{EventKind::surface_pair_one, 18, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 32, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 420:
    case 476:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 38, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 421:
        ctx.emit(Event{EventKind::surface_pair_one, 30, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 70, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 422:
        ctx.emit(Event{EventKind::resource_program, 0, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 14, 0u, 2u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 423:
        ctx.emit(Event{EventKind::resource_audio, 20, 0u, 6u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 428:
    case 452:
        ctx.emit(Event{EventKind::surface_pair_one, 10, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 28, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 433:
    case 726:
        ctx.emit(Event{EventKind::surface_pair_one, 34, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 434:
        ctx.emit(Event{EventKind::surface_pair_one, 32, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 435:
        ctx.emit(Event{EventKind::surface_pair_one, 14, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 38, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 436:
        ctx.emit(Event{EventKind::surface_pair_one, 26, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 68, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 449:
        ctx.emit(Event{EventKind::surface_pair_one, 8, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 457:
        ctx.emit(Event{EventKind::surface_pair_one, 18, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 36, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 458:
    case 472:
    case 473:
        ctx.emit(Event{EventKind::surface_pair_one, 12, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 32, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 459:
        ctx.emit(Event{EventKind::surface_pair_one, 12, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 36, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 460:
        ctx.emit(Event{EventKind::surface_pair_one, 30, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 72, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 464:
        ctx.emit(Event{EventKind::surface_pair_one, 12, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 466:
    case 469:
    case 471:
        ctx.emit(Event{EventKind::surface_pair_one, 32, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 46, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 467:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 32, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 475:
        ctx.emit(Event{EventKind::resource_program, 0, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 0, 5u, 29u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 16, 0u, 2u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 56, 0u, 3u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 98, 0u, 24u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 477:
        ctx.emit(Event{EventKind::surface_pair_one, 28, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 72, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 505:
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 46, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 90, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 507:
        ctx.emit(Event{EventKind::surface_pair_one, 32, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 50, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 96, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 511:
        ctx.emit(Event{EventKind::surface_pair_one, 32, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 50, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 70, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 512:
        ctx.emit(Event{EventKind::surface_pair_one, 28, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 42, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 56, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 80, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 513:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 84, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 304, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 370, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 517:
        ctx.emit(Event{EventKind::surface_pair_one, 4, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 64, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 518:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 80, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 519:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 34, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 36, 1u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 520:
        ctx.emit(Event{EventKind::surface_pair_one, 10, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 64, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 521:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 76, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 522:
        ctx.emit(Event{EventKind::surface_pair_one, 6, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 26, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 28, 1u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 523:
        ctx.emit(Event{EventKind::actor_audio, 12, 2u, 10u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 14, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 78, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 524:
        ctx.emit(Event{EventKind::surface_pair_one, 18, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 32, 2u, 10u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 78, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 525:
        ctx.emit(Event{EventKind::surface_pair_one, 11, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 16, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 40, 1u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 526:
        ctx.emit(Event{EventKind::surface_pair_one, 2, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 12, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 20, 2u, 10u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 527:
        ctx.emit(Event{EventKind::surface_pair_one, 14, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 20, 2u, 10u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 80, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 528:
        ctx.emit(Event{EventKind::surface_pair_one, 0, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 10, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 14, 2u, 8u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 529:
        ctx.emit(Event{EventKind::surface_pair_one, 44, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 104, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 530:
        ctx.emit(Event{EventKind::surface_pair_one, 2, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 72, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 531:
        ctx.emit(Event{EventKind::surface_pair_one, 14, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 30, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 32, 1u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 532:
        ctx.emit(Event{EventKind::surface_pair_one, 6, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 64, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 533:
        ctx.emit(Event{EventKind::surface_pair_one, 12, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 70, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 534:
        ctx.emit(Event{EventKind::surface_pair_one, 6, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 24, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 26, 1u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 538:
        ctx.emit(Event{EventKind::surface_pair_one, 54, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 66, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 539:
        ctx.emit(Event{EventKind::surface_pair_one, 47, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 106, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 540:
        ctx.emit(Event{EventKind::surface_pair_one, 7, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 17, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 541:
        ctx.emit(Event{EventKind::surface_pair_one, 35, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 42, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 542:
        ctx.emit(Event{EventKind::surface_pair_one, 113, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 153, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 546:
        ctx.emit(Event{EventKind::surface_pair_one, 102, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 132, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 54, 0u, 6u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 547:
        ctx.emit(Event{EventKind::surface_pair_one, 94, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 95, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 553:
        ctx.emit(Event{EventKind::surface_pair_one, 92, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 554:
        ctx.emit(Event{EventKind::surface_pair_one, 13, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 558:
        ctx.emit(Event{EventKind::surface_pair_one, 66, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 564:
        ctx.emit(Event{EventKind::actor_audio, 34, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 150, 0u, 6u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 150, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 224, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 282, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 424, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 460, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 436, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 472, 4u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 565:
        ctx.emit(Event{EventKind::surface_pair_one, 267, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 8, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 58, 4u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 566:
        ctx.emit(Event{EventKind::surface_pair_one, 96, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 567:
        ctx.emit(Event{EventKind::actor_audio, 30, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 150, 0u, 6u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 150, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 224, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 282, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 424, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 582:
        ctx.emit(Event{EventKind::surface_pair_one, 36, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 60, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 583:
        ctx.emit(Event{EventKind::surface_pair_one, 54, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 84, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 124, 3u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 162, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 584:
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 62, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 585:
        ctx.emit(Event{EventKind::surface_pair_one, 32, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 102, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 132, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 172, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 202, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 586:
    case 587:
        ctx.emit(Event{EventKind::surface_pair_one, 28, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 52, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 589:
        ctx.emit(Event{EventKind::surface_pair_one, 54, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 114, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 178, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 234, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 274, 2u, 12u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 590:
        ctx.emit(Event{EventKind::surface_pair_one, 2, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 56, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 110, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 148, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 204, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 242, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 288, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 316, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 596:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 16, 0u, 1u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 16, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::contact_action, 16, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 30, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 597:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 16, 0u, 1u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 16, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::contact_action, 16, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 28, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 598:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 22, 0u, 1u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 22, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::model_action, 24, 3u, 18u, 0u});
        ctx.emit(Event{EventKind::contact_action, 22, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 30, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 600:
        ctx.emit(Event{EventKind::surface_pair_one, 0, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 18, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 602:
        ctx.emit(Event{EventKind::resource_audio, 30, 0u, 1u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 30, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::contact_action, 32, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 40, 3u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 101, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 603:
        ctx.emit(Event{EventKind::resource_audio, 30, 0u, 1u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 30, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 30, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 38, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 44, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 604:
        ctx.emit(Event{EventKind::resource_audio, 36, 0u, 1u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 36, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 38, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 40, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 46, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 605:
        ctx.emit(Event{EventKind::surface_pair_one, 34, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 61, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 606:
        ctx.emit(Event{EventKind::surface_pair_one, 52, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 105, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 607:
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 74, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 611:
    case 614:
        ctx.emit(Event{EventKind::surface_pair_one, 12, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 38, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 54, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 616:
        ctx.emit(Event{EventKind::surface_pair_one, 30, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 617:
        ctx.emit(Event{EventKind::surface_pair_one, 18, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 38, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 62, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 619:
        ctx.emit(Event{EventKind::surface_pair_one, 58, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 725:
        ctx.emit(Event{EventKind::surface_pair_one, 26, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 54, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 94, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 727:
        ctx.emit(Event{EventKind::surface_pair_one, 48, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 84, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 102, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 123, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 728:
        ctx.emit(Event{EventKind::surface_pair_one, 38, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 60, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 90, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 116, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 138, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 180, 4u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 729:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 50, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 84, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 118, 4u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 733:
        ctx.emit(Event{EventKind::surface_pair_one, 28, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 54, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 72, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 734:
        ctx.emit(Event{EventKind::surface_pair_one, 34, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 72, 4u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 735:
        ctx.emit(Event{EventKind::surface_pair_one, 36, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 76, 4u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 737:
        ctx.emit(Event{EventKind::surface_pair_one, 24, 3u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 64, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 84, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 770:
    case 771:
        ctx.emit(Event{EventKind::surface_pair_one, 38, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 70, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 773:
    case 774:
        ctx.emit(Event{EventKind::surface_pair_one, 26, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 52, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 80, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 775:
    case 776:
        ctx.emit(Event{EventKind::surface_pair_one, 38, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 66, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 96, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 777:
        ctx.emit(Event{EventKind::surface_pair_one, 34, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 66, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 104, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 138, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 172, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 778:
        ctx.emit(Event{EventKind::surface_pair_one, 34, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 66, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 104, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 136, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 172, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 779:
        ctx.emit(Event{EventKind::surface_pair_one, 36, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 782:
        ctx.emit(Event{EventKind::surface_pair_one, 334, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 376, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 62, 0u, 6u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 838:
        ctx.emit(Event{EventKind::surface_pair_one, 30, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 50, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 840:
        ctx.emit(Event{EventKind::surface_pair_one, 40, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 64, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 841:
    case 849:
        ctx.emit(Event{EventKind::surface_pair_one, 12, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 34, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 54, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 846:
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 40, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 848:
        ctx.emit(Event{EventKind::surface_pair_one, 28, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 42, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 868:
        ctx.emit(Event{EventKind::surface_pair_one, 8, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 144, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 162, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 208, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 226, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 244, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 410, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 444, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 889:
        ctx.emit(Event{EventKind::surface_pair_one, 30, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 46, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 60, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 108, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 120, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 158, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 176, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 890:
        ctx.emit(Event{EventKind::surface_pair_one, 28, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 38, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 0, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 134, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 188, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 891:
        ctx.emit(Event{EventKind::actor_audio, 0, 2u, 3u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 895:
        ctx.emit(Event{EventKind::actor_audio, 0, 2u, 1u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 896:
        ctx.emit(Event{EventKind::surface_pair_one, 340, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 384, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 74, 0u, 6u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 897:
        ctx.emit(Event{EventKind::surface_pair_one, 215, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 238, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 297, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 313, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 898:
        ctx.emit(Event{EventKind::surface_pair_one, 13, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 127, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 336, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 899:
        ctx.emit(Event{EventKind::actor_audio, 0, 0u, 5u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 902:
        ctx.emit(Event{EventKind::surface_pair_one, 12, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 36, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 74, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 78, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 921:
        ctx.emit(Event{EventKind::actor_audio, 14, 2u, 8u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 922:
    case 923:
        ctx.emit(Event{EventKind::actor_audio, 10, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 38, 2u, 12u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 926:
        ctx.emit(Event{EventKind::surface_pair_one, 4, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    default:
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    }
}

void upper_one(Context& ctx, std::uint16_t selector) {
    switch (selector) {
    case 101:
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 58, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 24, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 58, 6u, 130u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 102:
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 54, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 22, 6u, 65u, 0u});
        ctx.emit(Event{EventKind::model_action, 54, 6u, 66u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 103:
        ctx.emit(Event{EventKind::surface_pair_one, 28, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 50, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 52, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 28, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 52, 6u, 130u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 104:
        ctx.emit(Event{EventKind::surface_pair_one, 8, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 124:
        ctx.emit(Event{EventKind::surface_pair_one, 26, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 76, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 26, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 76, 6u, 130u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 125:
        ctx.emit(Event{EventKind::surface_pair_one, 30, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 54, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 30, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 54, 6u, 130u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 126:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 68, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 116, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 164, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 16, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 68, 6u, 130u, 0u});
        ctx.emit(Event{EventKind::model_action, 116, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 164, 6u, 130u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 127:
        ctx.emit(Event{EventKind::surface_pair_one, 12, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 131:
        ctx.emit(Event{EventKind::actor_audio, 32, 2u, 10u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 132:
        ctx.emit(Event{EventKind::actor_audio, 70, 2u, 10u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 133:
    case 236:
    case 554:
        ctx.emit(Event{EventKind::surface_pair_one, 12, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 134:
        ctx.emit(Event{EventKind::surface_pair_one, 8, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 135:
        ctx.emit(Event{EventKind::surface_pair_one, 40, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 60, 3u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 46, 2u, 10u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 104, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 136:
        ctx.emit(Event{EventKind::actor_audio, 56, 2u, 10u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 52, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 44, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 137:
        ctx.emit(Event{EventKind::surface_pair_one, 38, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 68, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 114, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 114, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 92, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 138:
    case 139:
        ctx.emit(Event{EventKind::actor_audio, 22, 2u, 10u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 34, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 56, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 141:
        ctx.emit(Event{EventKind::surface_pair_one, 2, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 18, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 142:
        ctx.emit(Event{EventKind::surface_pair_one, 74, 3u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 34, 2u, 10u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 143:
        ctx.emit(Event{EventKind::surface_pair_one, 18, 3u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 68, 3u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 60, 2u, 10u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 146:
        ctx.emit(Event{EventKind::surface_pair_one, 40, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 80, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 149:
    case 372:
        ctx.emit(Event{EventKind::surface_pair_one, 2, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 151:
        ctx.emit(Event{EventKind::surface_pair_one, 76, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 134, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 150, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 153:
        ctx.emit(Event{EventKind::surface_pair_one, 86, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 176, 2u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 154:
        ctx.emit(Event{EventKind::model_action, 92, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 16, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 74, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 92, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 169:
        ctx.emit(Event{EventKind::surface_pair_one, 40, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 68, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 118, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 140, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 170:
        ctx.emit(Event{EventKind::surface_pair_one, 25, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 46, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 150, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 172, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 172:
        ctx.emit(Event{EventKind::surface_pair_one, 52, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 173:
        ctx.emit(Event{EventKind::surface_pair_one, 34, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 72, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 116, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 150, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 174:
        ctx.emit(Event{EventKind::surface_pair_one, 12, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 66, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 104, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 141, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 177:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 41, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 69, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 122, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 140, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 178:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 52, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 150, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 172, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 185:
        ctx.emit(Event{EventKind::surface_pair_one, 10, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 42, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 186:
        ctx.emit(Event{EventKind::surface_pair_one, 188, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 252, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 188:
        ctx.emit(Event{EventKind::surface_pair_one, 23, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 50, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 189:
        ctx.emit(Event{EventKind::surface_pair_one, 2, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 50, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 84, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 135, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 190:
        ctx.emit(Event{EventKind::surface_pair_one, 58, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 86, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 130, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 160, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 191:
    case 726:
        ctx.emit(Event{EventKind::surface_pair_one, 46, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 192:
        ctx.emit(Event{EventKind::surface_pair_one, 50, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 213:
        ctx.emit(Event{EventKind::surface_pair_one, 14, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 215:
    case 252:
    case 253:
        ctx.emit(Event{EventKind::contact_action, 20, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 20, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 227:
    case 599:
        ctx.emit(Event{EventKind::surface_pair_one, 10, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 231:
        ctx.emit(Event{EventKind::surface_pair_one, 2, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 41, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 73, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 116, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 140, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 190, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 232:
        ctx.emit(Event{EventKind::surface_pair_one, 2, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 74, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 110, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 165, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 196, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 233:
        ctx.emit(Event{EventKind::actor_audio, 10, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 38, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 54, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 10, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 24, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 235:
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 237:
        ctx.emit(Event{EventKind::surface_pair_one, 26, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 36, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 54, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 264:
        ctx.emit(Event{EventKind::resource_audio, 18, 0u, 1u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 18, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::contact_action, 18, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 28, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 265:
        ctx.emit(Event{EventKind::resource_audio, 16, 0u, 1u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 16, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::contact_action, 18, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 28, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 266:
        ctx.emit(Event{EventKind::resource_audio, 20, 0u, 1u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 20, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::contact_action, 18, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 28, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 268:
    case 269:
        ctx.emit(Event{EventKind::surface_pair_one, 26, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 270:
    case 271:
    case 272:
        ctx.emit(Event{EventKind::resource_audio, 0, 0u, 17u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 277:
    case 278:
    case 279:
        ctx.emit(Event{EventKind::resource_audio, 14, 0u, 1u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 14, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::contact_action, 14, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 20, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 281:
    case 582:
        ctx.emit(Event{EventKind::surface_pair_one, 36, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 60, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 282:
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 50, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 286:
        ctx.emit(Event{EventKind::surface_pair_one, 58, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 18, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::contact_action, 16, 0u, 126u, 0u});
        ctx.emit(Event{EventKind::contact_action, 22, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 340:
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 48, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 80, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 106, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 341:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 52, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 90, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 126, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 148, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 342:
        ctx.emit(Event{EventKind::surface_pair_one, 26, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 86, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 104, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 136, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 162, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 343:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 50, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 98, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 128, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 148, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 204, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 344:
    case 345:
    case 348:
    case 349:
        ctx.emit(Event{EventKind::node_audio, 36, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 346:
    case 347:
        if (ctx.actor.motion_class == 0x39) {
            ctx.emit(Event{EventKind::contact_action, 1, 0u, 200u, 0u});
            ctx.emit(Event{EventKind::contact_action, 100, 3u, 0u, 0u});
            common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        } else {
            common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        }
        return;
    case 352:
    case 856:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 356:
        ctx.emit(Event{EventKind::surface_pair_one, 14, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 36, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 357:
        ctx.emit(Event{EventKind::surface_pair_one, 48, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 361:
        ctx.emit(Event{EventKind::surface_pair_one, 12, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 36, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 86, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 365:
        ctx.emit(Event{EventKind::surface_pair_one, 34, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 262, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 288, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 366:
        ctx.emit(Event{EventKind::surface_pair_one, 38, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 260, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 290, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 370:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 397:
        ctx.emit(Event{EventKind::resource_audio, 30, 0u, 4u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 32, 0u, 4u, 0u});
        ctx.emit(Event{EventKind::resource_program, 0, 2u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 398:
        ctx.emit(Event{EventKind::resource_audio, 10, 0u, 2u, 0u});
        ctx.emit(Event{EventKind::resource_program, 0, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 401:
        ctx.emit(Event{EventKind::resource_audio, 16, 0u, 25u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 402:
        ctx.emit(Event{EventKind::resource_callback, 0, 0u, 0u, 0u});
        if ((ctx.metadata.action_flags(ctx.actor.resource_action) & 0x20) != 0) {
            ctx.emit(Event{EventKind::resource_audio, 10, 0u, 7u, 0u});
            common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        } else {
            common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        }
        return;
    case 403:
        ctx.emit(Event{EventKind::resource_audio, 10, 0u, 24u, 0u});
        ctx.emit(Event{EventKind::resource_program, 34, 5u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 410:
        ctx.emit(Event{EventKind::surface_pair_one, 40, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 412:
    case 415:
    case 417:
        ctx.emit(Event{EventKind::model_action, 40, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 40, 0u, 6u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 413:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 38, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 418:
    case 419:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 45, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 420:
        ctx.emit(Event{EventKind::surface_pair_one, 18, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 421:
        ctx.emit(Event{EventKind::surface_pair_one, 28, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 70, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 422:
        ctx.emit(Event{EventKind::resource_program, 0, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 14, 0u, 2u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 423:
        ctx.emit(Event{EventKind::resource_audio, 20, 0u, 6u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 428:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 36, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 433:
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 48, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 434:
        ctx.emit(Event{EventKind::surface_pair_one, 29, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 46, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 436:
        ctx.emit(Event{EventKind::surface_pair_one, 30, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 68, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 464:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 40, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 466:
    case 469:
        ctx.emit(Event{EventKind::surface_pair_one, 38, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 56, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 467:
        ctx.emit(Event{EventKind::surface_pair_one, 26, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 54, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 471:
        ctx.emit(Event{EventKind::surface_pair_one, 40, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 58, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 472:
        ctx.emit(Event{EventKind::surface_pair_one, 2, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 32, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 473:
    case 476:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 42, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 475:
        ctx.emit(Event{EventKind::resource_program, 0, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 0, 5u, 25u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 16, 0u, 2u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 72, 0u, 3u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 112, 0u, 24u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 477:
        ctx.emit(Event{EventKind::surface_pair_one, 28, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 68, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 505:
        ctx.emit(Event{EventKind::surface_pair_one, 28, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 38, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 507:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 48, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 66, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 511:
        ctx.emit(Event{EventKind::surface_pair_one, 26, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 40, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 86, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 512:
        ctx.emit(Event{EventKind::surface_pair_one, 4, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 36, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 70, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 513:
        ctx.emit(Event{EventKind::surface_pair_one, 304, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 517:
    case 518:
        ctx.emit(Event{EventKind::surface_pair_one, 30, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 84, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 519:
        ctx.emit(Event{EventKind::surface_pair_one, 12, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 30, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 32, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 520:
        ctx.emit(Event{EventKind::surface_pair_one, 12, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 66, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 521:
        ctx.emit(Event{EventKind::surface_pair_one, 18, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 74, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 522:
        ctx.emit(Event{EventKind::surface_pair_one, 10, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 28, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 30, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 523:
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 30, 2u, 10u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 524:
        ctx.emit(Event{EventKind::actor_audio, 30, 2u, 10u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 30, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 98, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 525:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 18, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 46, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 526:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 32, 2u, 10u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 70, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 527:
        ctx.emit(Event{EventKind::surface_pair_one, 12, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 18, 2u, 10u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 90, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 528:
        ctx.emit(Event{EventKind::surface_pair_one, 8, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 12, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 40, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 529:
        ctx.emit(Event{EventKind::surface_pair_one, 40, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 86, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 530:
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 90, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 531:
        ctx.emit(Event{EventKind::surface_pair_one, 14, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 30, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 32, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 532:
        ctx.emit(Event{EventKind::surface_pair_one, 12, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 68, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 533:
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 74, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 534:
        ctx.emit(Event{EventKind::surface_pair_one, 14, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 32, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 34, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 538:
        ctx.emit(Event{EventKind::surface_pair_one, 54, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 74, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 539:
        ctx.emit(Event{EventKind::surface_pair_one, 68, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 120, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 540:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 34, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 541:
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 40, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 542:
        ctx.emit(Event{EventKind::surface_pair_one, 150, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 162, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 546:
        ctx.emit(Event{EventKind::surface_pair_one, 100, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 44, 0u, 6u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 547:
    case 858:
        ctx.emit(Event{EventKind::surface_pair_one, 84, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 553:
        ctx.emit(Event{EventKind::surface_pair_one, 100, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 558:
        ctx.emit(Event{EventKind::surface_pair_one, 64, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 96, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 564:
        ctx.emit(Event{EventKind::actor_audio, 26, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 148, 0u, 6u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 148, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 232, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 310, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 354, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 424, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 474, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 502, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 570, 4u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 565:
        ctx.emit(Event{EventKind::surface_pair_one, 298, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 10, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 62, 4u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 566:
        ctx.emit(Event{EventKind::surface_pair_one, 92, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 567:
        ctx.emit(Event{EventKind::actor_audio, 30, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 148, 0u, 6u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 148, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 216, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 274, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 422, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 583:
        ctx.emit(Event{EventKind::surface_pair_one, 54, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 84, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 124, 3u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 162, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 584:
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 62, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 585:
        ctx.emit(Event{EventKind::surface_pair_one, 32, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 100, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 132, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 174, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 204, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 586:
    case 587:
        ctx.emit(Event{EventKind::surface_pair_one, 28, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 52, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 589:
        ctx.emit(Event{EventKind::surface_pair_one, 54, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 114, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 178, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 234, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 274, 2u, 12u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 590:
        ctx.emit(Event{EventKind::surface_pair_one, 2, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 56, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 110, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 148, 2u, 12u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 204, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 242, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 298, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 326, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 595:
        ctx.emit(Event{EventKind::surface_pair_one, 8, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 19, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 596:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 20, 0u, 1u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 20, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::contact_action, 18, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 34, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 597:
        ctx.emit(Event{EventKind::resource_audio, 20, 0u, 1u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 20, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 36, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 20, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 32, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 598:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 94, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 24, 0u, 1u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 24, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::model_action, 30, 3u, 18u, 0u});
        ctx.emit(Event{EventKind::contact_action, 26, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 38, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 600:
        ctx.emit(Event{EventKind::surface_pair_zero, 16, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_zero, 38, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 601:
        ctx.emit(Event{EventKind::surface_pair_zero, 20, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_zero, 40, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 602:
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 94, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 34, 0u, 1u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 34, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::contact_action, 36, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 42, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 603:
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 94, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 36, 0u, 1u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 36, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::contact_action, 38, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 44, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 604:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 94, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 34, 0u, 1u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 34, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::contact_action, 36, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 42, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 605:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 44, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 606:
        ctx.emit(Event{EventKind::surface_pair_one, 35, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 70, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 607:
        ctx.emit(Event{EventKind::surface_pair_one, 26, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 68, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 611:
    case 614:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 40, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 60, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 616:
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 34, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 617:
        ctx.emit(Event{EventKind::surface_pair_one, 18, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 43, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 619:
    case 779:
        ctx.emit(Event{EventKind::surface_pair_one, 36, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 725:
        ctx.emit(Event{EventKind::surface_pair_one, 35, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 60, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 727:
        ctx.emit(Event{EventKind::surface_pair_one, 50, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 84, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 102, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 122, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 728:
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 138, 3u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 196, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 729:
        ctx.emit(Event{EventKind::surface_pair_one, 24, 3u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 110, 3u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 733:
        ctx.emit(Event{EventKind::surface_pair_one, 48, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 75, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 734:
        ctx.emit(Event{EventKind::surface_pair_one, 2, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 76, 4u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 735:
        ctx.emit(Event{EventKind::surface_pair_one, 24, 4u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 737:
        ctx.emit(Event{EventKind::surface_pair_one, 24, 3u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 52, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 74, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 739:
        ctx.emit(Event{EventKind::surface_pair_one, 58, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 760:
        ctx.emit(Event{EventKind::surface_pair_one, 15, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 770:
    case 771:
        ctx.emit(Event{EventKind::surface_pair_one, 10, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 32, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 48, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 66, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 773:
    case 774:
        ctx.emit(Event{EventKind::surface_pair_one, 26, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 52, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 80, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 775:
    case 776:
        ctx.emit(Event{EventKind::surface_pair_one, 36, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 54, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 68, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 777:
        ctx.emit(Event{EventKind::surface_pair_one, 34, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 66, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 104, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 138, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 172, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 778:
        ctx.emit(Event{EventKind::surface_pair_one, 34, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 66, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 104, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 136, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 172, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 782:
        ctx.emit(Event{EventKind::surface_pair_one, 334, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 376, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 62, 0u, 6u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 792:
        ctx.emit(Event{EventKind::surface_pair_one, 72, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 96, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 125, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 793:
        ctx.emit(Event{EventKind::surface_pair_one, 60, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 63, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 838:
        ctx.emit(Event{EventKind::surface_pair_one, 30, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 50, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 840:
        ctx.emit(Event{EventKind::surface_pair_one, 40, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 64, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 841:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 848:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 26, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 50, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 68, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 853:
    case 855:
        ctx.emit(Event{EventKind::surface_pair_one, 25, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 868:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 50, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 10, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 150, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 170, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 213, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 228, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 253, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 405, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 437, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 875:
        ctx.emit(Event{EventKind::surface_pair_one, 56, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 877:
        ctx.emit(Event{EventKind::surface_pair_one, 66, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 880:
        ctx.emit(Event{EventKind::surface_pair_one, 37, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 62, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 882:
        ctx.emit(Event{EventKind::surface_pair_one, 65, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 87, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 885:
        ctx.emit(Event{EventKind::surface_pair_one, 21, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 58, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 886:
        ctx.emit(Event{EventKind::surface_pair_one, 64, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 92, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 887:
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 66, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 888:
        ctx.emit(Event{EventKind::surface_pair_one, 65, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 90, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 889:
        ctx.emit(Event{EventKind::surface_pair_one, 30, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 46, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 60, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 108, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 120, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 158, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 176, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 890:
        ctx.emit(Event{EventKind::surface_pair_one, 28, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 38, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 0, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 134, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 188, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 891:
        ctx.emit(Event{EventKind::actor_audio, 0, 2u, 3u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 895:
        ctx.emit(Event{EventKind::actor_audio, 0, 2u, 1u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 896:
        ctx.emit(Event{EventKind::surface_pair_one, 340, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 384, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 74, 0u, 6u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 897:
        ctx.emit(Event{EventKind::surface_pair_one, 215, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 238, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 297, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 313, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 898:
        ctx.emit(Event{EventKind::surface_pair_one, 13, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 127, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 336, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 899:
        ctx.emit(Event{EventKind::actor_audio, 0, 0u, 5u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 901:
        ctx.emit(Event{EventKind::surface_pair_one, 38, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 902:
        ctx.emit(Event{EventKind::surface_pair_one, 12, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 36, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 72, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 76, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 910:
        ctx.emit(Event{EventKind::surface_pair_one, 28, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 921:
        ctx.emit(Event{EventKind::actor_audio, 14, 2u, 8u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 922:
    case 923:
        ctx.emit(Event{EventKind::actor_audio, 10, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 38, 2u, 12u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 926:
        ctx.emit(Event{EventKind::surface_pair_one, 4, 0u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    case 931:
        ctx.emit(Event{EventKind::position_audio, 110, 183u, 0u, 0u});
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    default:
        common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);
        return;
    }
}
