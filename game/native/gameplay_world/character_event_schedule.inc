// Recovered from eight complete owned character event bodies.
// First read: upper selector; fresh second read: lower selector.
void character_0_upper(Context& ctx, std::uint16_t selector) {
    (void)ctx;
    switch (selector) {
    case 101:
        ctx.emit(Event{EventKind::surface_pair_one, 30, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 72, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 124, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 30, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 72, 6u, 130u, 0u});
        ctx.emit(Event{EventKind::model_action, 124, 6u, 129u, 0u});
        return;
    case 102:
        ctx.emit(Event{EventKind::surface_pair_one, 26, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 72, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 118, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 162, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 26, 6u, 65u, 0u});
        ctx.emit(Event{EventKind::model_action, 72, 6u, 66u, 0u});
        ctx.emit(Event{EventKind::model_action, 118, 6u, 65u, 0u});
        ctx.emit(Event{EventKind::model_action, 162, 6u, 66u, 0u});
        return;
    case 103:
        ctx.emit(Event{EventKind::surface_pair_one, 28, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 50, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 58, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::model_action, 28, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 50, 6u, 130u, 0u});
        return;
    case 104:
        ctx.emit(Event{EventKind::surface_pair_one, 8, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 18, 0u, 0u, 0u});
        return;
    case 301:
        ctx.emit(Event{EventKind::surface_pair_one, 52, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 16, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::contact_action, 14, 0u, 120u, 0u});
        ctx.emit(Event{EventKind::contact_action, 22, 3u, 0u, 0u});
        return;
    case 370:
    case 372:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        return;
    default:return;
    }
}

void character_0_lower(Context& ctx, std::uint16_t selector) {
    (void)ctx;
    switch (selector) {
    case 378:
        ctx.emit(Event{EventKind::surface_pair_one, 10, 0u, 0u, 0u});
        return;
    case 379:
        ctx.emit(Event{EventKind::surface_pair_one, 8, 0u, 0u, 0u});
        return;
    default:return;
    }
}

void character_1_upper(Context& ctx, std::uint16_t selector) {
    (void)ctx;
    switch (selector) {
    case 101:
        ctx.emit(Event{EventKind::surface_pair_one, 34, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 72, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 110, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 34, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 72, 6u, 130u, 0u});
        ctx.emit(Event{EventKind::model_action, 110, 6u, 129u, 0u});
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
        return;
    case 103:
        ctx.emit(Event{EventKind::surface_pair_one, 28, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 54, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 58, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::model_action, 28, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 54, 6u, 130u, 0u});
        return;
    case 104:
        ctx.emit(Event{EventKind::surface_pair_one, 8, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        return;
    case 304:
        ctx.emit(Event{EventKind::actor_audio, 22, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::contact_action, 30, 0u, 122u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 48, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 96, 0u, 0u, 0u});
        return;
    case 307:
        ctx.emit(Event{EventKind::surface_pair_one, 38, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 70, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::resource_audio, 18, 0u, 1u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 18, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::contact_action, 12, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 20, 3u, 0u, 0u});
        return;
    case 370:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        return;
    case 372:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        return;
    default:return;
    }
}

void character_1_lower(Context& ctx, std::uint16_t selector) {
    (void)ctx;
    switch (selector) {
    case 378:
        ctx.emit(Event{EventKind::surface_pair_one, 18, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 32, 0u, 0u, 0u});
        return;
    case 379:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        return;
    default:return;
    }
}

void character_2_upper(Context& ctx, std::uint16_t selector) {
    (void)ctx;
    switch (selector) {
    case 101:
        ctx.emit(Event{EventKind::surface_pair_one, 34, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 76, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 34, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 76, 6u, 130u, 0u});
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
        return;
    case 103:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 42, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 54, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::model_action, 20, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 42, 6u, 130u, 0u});
        return;
    case 104:
        ctx.emit(Event{EventKind::surface_pair_one, 8, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        return;
    case 293:
        ctx.emit(Event{EventKind::character_callback, 0, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 94, 0u, 16u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 182, 0u, 17u, 0u});
        return;
    case 300:
        ctx.emit(Event{EventKind::actor_audio, 0, 0u, 18u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 32, 2u, 0u, 0u});
        return;
    case 301:
        ctx.emit(Event{EventKind::surface_pair_one, 40, 0u, 0u, 0u});
        return;
    default:return;
    }
}

void character_2_lower(Context& ctx, std::uint16_t selector) {
    (void)ctx;
    switch (selector) {
    default:return;
    }
}

void character_3_upper(Context& ctx, std::uint16_t selector) {
    (void)ctx;
    switch (selector) {
    case 101:
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 70, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 116, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 24, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 70, 6u, 130u, 0u});
        ctx.emit(Event{EventKind::model_action, 116, 6u, 129u, 0u});
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
        return;
    case 103:
        ctx.emit(Event{EventKind::surface_pair_one, 30, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 54, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 42, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::model_action, 30, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 54, 6u, 130u, 0u});
        return;
    case 104:
        ctx.emit(Event{EventKind::surface_pair_one, 8, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        return;
    case 301:
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 42, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 78, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 14, 2u, 3u, 0u});
        if (ctx.actor.secondary == 15) {
            ctx.emit(Event{EventKind::contact_action, 10, 0u, 121u, 0u});
            ctx.emit(Event{EventKind::contact_action, 22, 3u, 0u, 0u});
        } else {
            ctx.emit(Event{EventKind::contact_action, 10, 0u, 125u, 0u});
            ctx.emit(Event{EventKind::contact_action, 22, 3u, 0u, 0u});
        }
        return;
    default:return;
    }
}

void character_3_lower(Context& ctx, std::uint16_t selector) {
    (void)ctx;
    switch (selector) {
    default:return;
    }
}

void character_4_upper(Context& ctx, std::uint16_t selector) {
    (void)ctx;
    switch (selector) {
    case 101:
        ctx.emit(Event{EventKind::surface_pair_one, 46, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 102, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 46, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 102, 6u, 130u, 0u});
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
        return;
    case 103:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 42, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 46, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::model_action, 20, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 42, 6u, 130u, 0u});
        return;
    case 104:
        ctx.emit(Event{EventKind::surface_pair_one, 8, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        return;
    case 300:
        ctx.emit(Event{EventKind::surface_pair_one, 14, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 16, 2u, 3u, 0u});
        return;
    case 301:
        ctx.emit(Event{EventKind::resource_audio, 14, 0u, 1u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 14, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::contact_action, 10, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 18, 3u, 0u, 0u});
        return;
    case 302:
        ctx.emit(Event{EventKind::resource_audio, 18, 0u, 1u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 18, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::contact_action, 14, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 22, 3u, 0u, 0u});
        return;
    case 303:
        ctx.emit(Event{EventKind::resource_audio, 10, 0u, 1u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 10, 2u, 3u, 0u});
        ctx.emit(Event{EventKind::contact_action, 6, 2u, 0u, 0u});
        ctx.emit(Event{EventKind::contact_action, 14, 3u, 0u, 0u});
        return;
    case 370:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        return;
    case 372:
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        return;
    default:return;
    }
}

void character_4_lower(Context& ctx, std::uint16_t selector) {
    (void)ctx;
    switch (selector) {
    case 378:
        ctx.emit(Event{EventKind::surface_pair_one, 4, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 26, 0u, 0u, 0u});
        return;
    case 379:
        ctx.emit(Event{EventKind::surface_pair_one, 20, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 36, 0u, 0u, 0u});
        return;
    default:return;
    }
}

void character_5_upper(Context& ctx, std::uint16_t selector) {
    (void)ctx;
    switch (selector) {
    case 101:
        ctx.emit(Event{EventKind::surface_pair_one, 46, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 86, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 126, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 46, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 86, 6u, 130u, 0u});
        ctx.emit(Event{EventKind::model_action, 126, 6u, 129u, 0u});
        return;
    case 102:
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 78, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 132, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 180, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 22, 6u, 65u, 0u});
        ctx.emit(Event{EventKind::model_action, 78, 6u, 66u, 0u});
        ctx.emit(Event{EventKind::model_action, 132, 6u, 65u, 0u});
        ctx.emit(Event{EventKind::model_action, 180, 6u, 66u, 0u});
        return;
    case 103:
        ctx.emit(Event{EventKind::surface_pair_one, 28, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 52, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 58, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::model_action, 28, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 52, 6u, 130u, 0u});
        return;
    case 104:
        ctx.emit(Event{EventKind::surface_pair_one, 8, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        return;
    case 300:
        ctx.emit(Event{EventKind::surface_pair_one, 14, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 42, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 52, 0u, 0u, 0u});
        return;
    default:return;
    }
}

void character_5_lower(Context& ctx, std::uint16_t selector) {
    (void)ctx;
    switch (selector) {
    default:return;
    }
}

void character_6_upper(Context& ctx, std::uint16_t selector) {
    (void)ctx;
    switch (selector) {
    case 101:
        ctx.emit(Event{EventKind::surface_pair_one, 36, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 76, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 36, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 76, 6u, 130u, 0u});
        return;
    case 102:
        ctx.emit(Event{EventKind::surface_pair_one, 22, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 78, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 132, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 180, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 22, 6u, 65u, 0u});
        ctx.emit(Event{EventKind::model_action, 78, 6u, 66u, 0u});
        ctx.emit(Event{EventKind::model_action, 132, 6u, 65u, 0u});
        ctx.emit(Event{EventKind::model_action, 180, 6u, 66u, 0u});
        return;
    case 103:
        ctx.emit(Event{EventKind::surface_pair_one, 26, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 50, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 74, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 52, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::model_action, 26, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 50, 6u, 130u, 0u});
        ctx.emit(Event{EventKind::model_action, 74, 6u, 129u, 0u});
        return;
    case 104:
        ctx.emit(Event{EventKind::surface_pair_one, 8, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        return;
    case 300:
        ctx.emit(Event{EventKind::actor_audio, 10, 0u, 16u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 14, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 16, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 32, 4u, 0u, 0u});
        return;
    case 301:
        ctx.emit(Event{EventKind::surface_pair_one, 4, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 8, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 22, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 36, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 48, 4u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 62, 4u, 0u, 0u});
        return;
    case 302:
        ctx.emit(Event{EventKind::surface_pair_one, 12, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 30, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 42, 0u, 0u, 0u});
        return;
    default:return;
    }
}

void character_6_lower(Context& ctx, std::uint16_t selector) {
    (void)ctx;
    switch (selector) {
    default:return;
    }
}

void character_7_upper(Context& ctx, std::uint16_t selector) {
    (void)ctx;
    switch (selector) {
    case 101:
        ctx.emit(Event{EventKind::surface_pair_one, 26, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 70, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 26, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 70, 6u, 130u, 0u});
        return;
    case 102:
        ctx.emit(Event{EventKind::surface_pair_one, 26, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 78, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 126, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 177, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::model_action, 26, 6u, 65u, 0u});
        ctx.emit(Event{EventKind::model_action, 78, 6u, 66u, 0u});
        ctx.emit(Event{EventKind::model_action, 126, 6u, 65u, 0u});
        ctx.emit(Event{EventKind::model_action, 177, 6u, 66u, 0u});
        return;
    case 103:
        ctx.emit(Event{EventKind::surface_pair_one, 22, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 48, 1u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 52, 2u, 8u, 0u});
        ctx.emit(Event{EventKind::model_action, 22, 6u, 129u, 0u});
        ctx.emit(Event{EventKind::model_action, 48, 6u, 130u, 0u});
        return;
    case 104:
        ctx.emit(Event{EventKind::surface_pair_one, 8, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 24, 0u, 0u, 0u});
        return;
    case 293:
        ctx.emit(Event{EventKind::surface_pair_one, 40, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::surface_pair_one, 62, 0u, 0u, 0u});
        return;
    case 300:
        ctx.emit(Event{EventKind::surface_pair_one, 10, 0u, 0u, 0u});
        ctx.emit(Event{EventKind::actor_audio, 10, 2u, 8u, 0u});
        return;
    default:return;
    }
}

void character_7_lower(Context& ctx, std::uint16_t selector) {
    (void)ctx;
    switch (selector) {
    default:return;
    }
}
