#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CA3F0
// Address: 0x1ca3f0 - 0x1cb074
void sub_001CA3F0_0x1ca3f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CA3F0_0x1ca3f0");
#endif

    switch (ctx->pc) {
        case 0x1ca43cu: goto label_1ca43c;
        case 0x1ca5d8u: goto label_1ca5d8;
        case 0x1ca630u: goto label_1ca630;
        case 0x1ca6ecu: goto label_1ca6ec;
        case 0x1ca740u: goto label_1ca740;
        case 0x1ca820u: goto label_1ca820;
        case 0x1ca9a4u: goto label_1ca9a4;
        case 0x1ca9b4u: goto label_1ca9b4;
        case 0x1caa24u: goto label_1caa24;
        case 0x1cab04u: goto label_1cab04;
        case 0x1cabb8u: goto label_1cabb8;
        case 0x1cabf8u: goto label_1cabf8;
        case 0x1cac60u: goto label_1cac60;
        case 0x1cace0u: goto label_1cace0;
        case 0x1cad00u: goto label_1cad00;
        case 0x1cad34u: goto label_1cad34;
        case 0x1cad90u: goto label_1cad90;
        case 0x1cadbcu: goto label_1cadbc;
        case 0x1cae78u: goto label_1cae78;
        case 0x1cae84u: goto label_1cae84;
        case 0x1caed8u: goto label_1caed8;
        case 0x1caf24u: goto label_1caf24;
        case 0x1caf38u: goto label_1caf38;
        case 0x1cb00cu: goto label_1cb00c;
        default: break;
    }

    ctx->pc = 0x1ca3f0u;

    // 0x1ca3f0: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x1ca3f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x1ca3f4: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x1ca3f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x1ca3f8: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x1ca3f8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x1ca3fc: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1ca3fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1ca400: 0x160b82d  daddu       $s7, $t3, $zero
    ctx->pc = 0x1ca400u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca404: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1ca404u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1ca408: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x1ca408u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca40c: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1ca40cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1ca410: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x1ca410u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca414: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1ca414u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1ca418: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x1ca418u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca41c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1ca41cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1ca420: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x1ca420u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca424: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ca424u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ca428: 0x100902d  daddu       $s2, $t0, $zero
    ctx->pc = 0x1ca428u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca42c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ca42cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ca430: 0x120882d  daddu       $s1, $t1, $zero
    ctx->pc = 0x1ca430u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca434: 0xc0725ac  jal         func_1C96B0
    ctx->pc = 0x1CA434u;
    SET_GPR_U32(ctx, 31, 0x1CA43Cu);
    ctx->pc = 0x1CA438u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA434u;
            // 0x1ca438: 0x140802d  daddu       $s0, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C96B0u;
    if (runtime->hasFunction(0x1C96B0u)) {
        auto targetFn = runtime->lookupFunction(0x1C96B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA43Cu; }
        if (ctx->pc != 0x1CA43Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C96B0_0x1c96b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA43Cu; }
        if (ctx->pc != 0x1CA43Cu) { return; }
    }
    ctx->pc = 0x1CA43Cu;
label_1ca43c:
    // 0x1ca43c: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CA43Cu;
    {
        const bool branch_taken_0x1ca43c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1CA440u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA43Cu;
            // 0x1ca440: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca43c) {
            ctx->pc = 0x1CA474u;
            goto label_1ca474;
        }
    }
    ctx->pc = 0x1CA444u;
    // 0x1ca444: 0x2402ffaf  addiu       $v0, $zero, -0x51
    ctx->pc = 0x1ca444u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967215));
    // 0x1ca448: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1ca448u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca44c: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1ca44cu;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca450: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1ca450u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca454: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca454u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca458: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1ca458u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca45c: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca45cu;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca460: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca460u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca464: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca464u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca468: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca468u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca46c: 0x100002f6  b           . + 4 + (0x2F6 << 2)
    ctx->pc = 0x1CA46Cu;
    {
        const bool branch_taken_0x1ca46c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA470u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA46Cu;
            // 0x1ca470: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca46c) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA474u;
label_1ca474:
    // 0x1ca474: 0x9023c6ec  lbu         $v1, -0x3914($at)
    ctx->pc = 0x1ca474u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1ca478: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca478u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca47c: 0x9022c6ed  lbu         $v0, -0x3913($at)
    ctx->pc = 0x1ca47cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952685)));
    // 0x1ca480: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1ca480u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1ca484: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CA484u;
    {
        const bool branch_taken_0x1ca484 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ca484) {
            ctx->pc = 0x1CA490u;
            goto label_1ca490;
        }
    }
    ctx->pc = 0x1CA48Cu;
    // 0x1ca48c: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1ca48cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1ca490:
    // 0x1ca490: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca490u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca494: 0x24040064  addiu       $a0, $zero, 0x64
    ctx->pc = 0x1ca494u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1ca498: 0xa023c6ed  sb          $v1, -0x3913($at)
    ctx->pc = 0x1ca498u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952685), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca49c: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1ca49cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1ca4a0: 0x106402d7  beq         $v1, $a0, . + 4 + (0x2D7 << 2)
    ctx->pc = 0x1CA4A0u;
    {
        const bool branch_taken_0x1ca4a0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1CA4A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA4A0u;
            // 0x1ca4a4: 0x24020063  addiu       $v0, $zero, 0x63 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca4a0) {
            ctx->pc = 0x1CB000u;
            goto label_1cb000;
        }
    }
    ctx->pc = 0x1CA4A8u;
    // 0x1ca4a8: 0x106202cf  beq         $v1, $v0, . + 4 + (0x2CF << 2)
    ctx->pc = 0x1CA4A8u;
    {
        const bool branch_taken_0x1ca4a8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1ca4a8) {
            ctx->pc = 0x1CAFE8u;
            goto label_1cafe8;
        }
    }
    ctx->pc = 0x1CA4B0u;
    // 0x1ca4b0: 0x2402001f  addiu       $v0, $zero, 0x1F
    ctx->pc = 0x1ca4b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x1ca4b4: 0x106202bf  beq         $v1, $v0, . + 4 + (0x2BF << 2)
    ctx->pc = 0x1CA4B4u;
    {
        const bool branch_taken_0x1ca4b4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CA4B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA4B4u;
            // 0x1ca4b8: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca4b4) {
            ctx->pc = 0x1CAFB4u;
            goto label_1cafb4;
        }
    }
    ctx->pc = 0x1CA4BCu;
    // 0x1ca4bc: 0x2402001e  addiu       $v0, $zero, 0x1E
    ctx->pc = 0x1ca4bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
    // 0x1ca4c0: 0x10620296  beq         $v1, $v0, . + 4 + (0x296 << 2)
    ctx->pc = 0x1CA4C0u;
    {
        const bool branch_taken_0x1ca4c0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CA4C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA4C0u;
            // 0x1ca4c4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca4c0) {
            ctx->pc = 0x1CAF1Cu;
            goto label_1caf1c;
        }
    }
    ctx->pc = 0x1CA4C8u;
    // 0x1ca4c8: 0x24040018  addiu       $a0, $zero, 0x18
    ctx->pc = 0x1ca4c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1ca4cc: 0x10640243  beq         $v1, $a0, . + 4 + (0x243 << 2)
    ctx->pc = 0x1CA4CCu;
    {
        const bool branch_taken_0x1ca4cc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1CA4D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA4CCu;
            // 0x1ca4d0: 0x24040017  addiu       $a0, $zero, 0x17 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 23));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca4cc) {
            ctx->pc = 0x1CADDCu;
            goto label_1caddc;
        }
    }
    ctx->pc = 0x1CA4D4u;
    // 0x1ca4d4: 0x106401dc  beq         $v1, $a0, . + 4 + (0x1DC << 2)
    ctx->pc = 0x1CA4D4u;
    {
        const bool branch_taken_0x1ca4d4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1ca4d4) {
            ctx->pc = 0x1CAC48u;
            goto label_1cac48;
        }
    }
    ctx->pc = 0x1CA4DCu;
    // 0x1ca4dc: 0x24040016  addiu       $a0, $zero, 0x16
    ctx->pc = 0x1ca4dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
    // 0x1ca4e0: 0x106401b3  beq         $v1, $a0, . + 4 + (0x1B3 << 2)
    ctx->pc = 0x1CA4E0u;
    {
        const bool branch_taken_0x1ca4e0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1CA4E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA4E0u;
            // 0x1ca4e4: 0x24040015  addiu       $a0, $zero, 0x15 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca4e0) {
            ctx->pc = 0x1CABB0u;
            goto label_1cabb0;
        }
    }
    ctx->pc = 0x1CA4E8u;
    // 0x1ca4e8: 0x10640162  beq         $v1, $a0, . + 4 + (0x162 << 2)
    ctx->pc = 0x1CA4E8u;
    {
        const bool branch_taken_0x1ca4e8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1CA4ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA4E8u;
            // 0x1ca4ec: 0x24050014  addiu       $a1, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca4e8) {
            ctx->pc = 0x1CAA74u;
            goto label_1caa74;
        }
    }
    ctx->pc = 0x1CA4F0u;
    // 0x1ca4f0: 0x10650141  beq         $v1, $a1, . + 4 + (0x141 << 2)
    ctx->pc = 0x1CA4F0u;
    {
        const bool branch_taken_0x1ca4f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        ctx->pc = 0x1CA4F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA4F0u;
            // 0x1ca4f4: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca4f0) {
            ctx->pc = 0x1CA9F8u;
            goto label_1ca9f8;
        }
    }
    ctx->pc = 0x1CA4F8u;
    // 0x1ca4f8: 0x2404000d  addiu       $a0, $zero, 0xD
    ctx->pc = 0x1ca4f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1ca4fc: 0x106400f5  beq         $v1, $a0, . + 4 + (0xF5 << 2)
    ctx->pc = 0x1CA4FCu;
    {
        const bool branch_taken_0x1ca4fc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1CA500u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA4FCu;
            // 0x1ca500: 0x2404000c  addiu       $a0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca4fc) {
            ctx->pc = 0x1CA8D4u;
            goto label_1ca8d4;
        }
    }
    ctx->pc = 0x1CA504u;
    // 0x1ca504: 0x106400a2  beq         $v1, $a0, . + 4 + (0xA2 << 2)
    ctx->pc = 0x1CA504u;
    {
        const bool branch_taken_0x1ca504 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1ca504) {
            ctx->pc = 0x1CA790u;
            goto label_1ca790;
        }
    }
    ctx->pc = 0x1CA50Cu;
    // 0x1ca50c: 0x2402000b  addiu       $v0, $zero, 0xB
    ctx->pc = 0x1ca50cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x1ca510: 0x10620089  beq         $v1, $v0, . + 4 + (0x89 << 2)
    ctx->pc = 0x1CA510u;
    {
        const bool branch_taken_0x1ca510 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CA514u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA510u;
            // 0x1ca514: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca510) {
            ctx->pc = 0x1CA738u;
            goto label_1ca738;
        }
    }
    ctx->pc = 0x1CA518u;
    // 0x1ca518: 0x2404000a  addiu       $a0, $zero, 0xA
    ctx->pc = 0x1ca518u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1ca51c: 0x10640060  beq         $v1, $a0, . + 4 + (0x60 << 2)
    ctx->pc = 0x1CA51Cu;
    {
        const bool branch_taken_0x1ca51c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1CA520u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA51Cu;
            // 0x1ca520: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca51c) {
            ctx->pc = 0x1CA6A0u;
            goto label_1ca6a0;
        }
    }
    ctx->pc = 0x1CA524u;
    // 0x1ca524: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1ca524u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1ca528: 0x1062003e  beq         $v1, $v0, . + 4 + (0x3E << 2)
    ctx->pc = 0x1CA528u;
    {
        const bool branch_taken_0x1ca528 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CA52Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA528u;
            // 0x1ca52c: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca528) {
            ctx->pc = 0x1CA624u;
            goto label_1ca624;
        }
    }
    ctx->pc = 0x1CA530u;
    // 0x1ca530: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1ca530u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca534: 0x10620022  beq         $v1, $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x1CA534u;
    {
        const bool branch_taken_0x1ca534 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CA538u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA534u;
            // 0x1ca538: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca534) {
            ctx->pc = 0x1CA5C0u;
            goto label_1ca5c0;
        }
    }
    ctx->pc = 0x1CA53Cu;
    // 0x1ca53c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ca53cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ca540: 0x1062000e  beq         $v1, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1CA540u;
    {
        const bool branch_taken_0x1ca540 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1ca540) {
            ctx->pc = 0x1CA57Cu;
            goto label_1ca57c;
        }
    }
    ctx->pc = 0x1CA548u;
    // 0x1ca548: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CA548u;
    {
        const bool branch_taken_0x1ca548 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ca548) {
            ctx->pc = 0x1CA558u;
            goto label_1ca558;
        }
    }
    ctx->pc = 0x1CA550u;
    // 0x1ca550: 0x100002bd  b           . + 4 + (0x2BD << 2)
    ctx->pc = 0x1CA550u;
    {
        const bool branch_taken_0x1ca550 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA554u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA550u;
            // 0x1ca554: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca550) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA558u;
label_1ca558:
    // 0x1ca558: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1ca558u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ca55c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca55cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca560: 0xa2a30000  sb          $v1, 0x0($s5)
    ctx->pc = 0x1ca560u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca564: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca564u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca568: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca568u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca56c: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca56cu;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca570: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca570u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca574: 0x100002b4  b           . + 4 + (0x2B4 << 2)
    ctx->pc = 0x1CA574u;
    {
        const bool branch_taken_0x1ca574 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA574u;
            // 0x1ca578: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca574) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA57Cu;
label_1ca57c:
    // 0x1ca57c: 0x86630000  lh          $v1, 0x0($s3)
    ctx->pc = 0x1ca57cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1ca580: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x1ca580u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1ca584: 0x3082a  slt         $at, $zero, $v1
    ctx->pc = 0x1ca584u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1ca588: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CA588u;
    {
        const bool branch_taken_0x1ca588 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA58Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA588u;
            // 0x1ca58c: 0xa6620000  sh          $v0, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca588) {
            ctx->pc = 0x1CA598u;
            goto label_1ca598;
        }
    }
    ctx->pc = 0x1CA590u;
    // 0x1ca590: 0x100002ad  b           . + 4 + (0x2AD << 2)
    ctx->pc = 0x1CA590u;
    {
        const bool branch_taken_0x1ca590 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA594u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA590u;
            // 0x1ca594: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca590) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA598u;
label_1ca598:
    // 0x1ca598: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca598u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca59c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca59cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca5a0: 0xa024c6ee  sb          $a0, -0x3912($at)
    ctx->pc = 0x1ca5a0u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 4));
    // 0x1ca5a4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca5a4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca5a8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca5a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca5ac: 0xa020c6ec  sb          $zero, -0x3914($at)
    ctx->pc = 0x1ca5acu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca5b0: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1ca5b0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1ca5b4: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1ca5b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ca5b8: 0x100002a3  b           . + 4 + (0x2A3 << 2)
    ctx->pc = 0x1CA5B8u;
    {
        const bool branch_taken_0x1ca5b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA5BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA5B8u;
            // 0x1ca5bc: 0xa2a30000  sb          $v1, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca5b8) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA5C0u;
label_1ca5c0:
    // 0x1ca5c0: 0xa022c6ec  sb          $v0, -0x3914($at)
    ctx->pc = 0x1ca5c0u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca5c4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca5c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca5c8: 0x8c22d158  lw          $v0, -0x2EA8($at)
    ctx->pc = 0x1ca5c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955352)));
    // 0x1ca5cc: 0x8c450004  lw          $a1, 0x4($v0)
    ctx->pc = 0x1ca5ccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1ca5d0: 0xc075a2c  jal         func_1D68B0
    ctx->pc = 0x1CA5D0u;
    SET_GPR_U32(ctx, 31, 0x1CA5D8u);
    ctx->pc = 0x1CA5D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA5D0u;
            // 0x1ca5d4: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D68B0u;
    if (runtime->hasFunction(0x1D68B0u)) {
        auto targetFn = runtime->lookupFunction(0x1D68B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA5D8u; }
        if (ctx->pc != 0x1CA5D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D68B0_0x1d68b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA5D8u; }
        if (ctx->pc != 0x1CA5D8u) { return; }
    }
    ctx->pc = 0x1CA5D8u;
label_1ca5d8:
    // 0x1ca5d8: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CA5D8u;
    {
        const bool branch_taken_0x1ca5d8 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1ca5d8) {
            ctx->pc = 0x1CA610u;
            goto label_1ca610;
        }
    }
    ctx->pc = 0x1CA5E0u;
    // 0x1ca5e0: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1ca5e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1ca5e4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1ca5e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca5e8: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1ca5e8u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca5ec: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1ca5ecu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca5f0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca5f0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca5f4: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1ca5f4u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca5f8: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca5f8u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca5fc: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca5fcu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca600: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca600u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca604: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca604u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca608: 0x1000028f  b           . + 4 + (0x28F << 2)
    ctx->pc = 0x1CA608u;
    {
        const bool branch_taken_0x1ca608 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA60Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA608u;
            // 0x1ca60c: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca608) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA610u;
label_1ca610:
    // 0x1ca610: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1ca610u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1ca614: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca614u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca618: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1ca618u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ca61c: 0x1000028a  b           . + 4 + (0x28A << 2)
    ctx->pc = 0x1CA61Cu;
    {
        const bool branch_taken_0x1ca61c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA620u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA61Cu;
            // 0x1ca620: 0xa2a30000  sb          $v1, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca61c) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA624u;
label_1ca624:
    // 0x1ca624: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca624u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca628: 0xc075cb0  jal         func_1D72C0
    ctx->pc = 0x1CA628u;
    SET_GPR_U32(ctx, 31, 0x1CA630u);
    ctx->pc = 0x1CA62Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA628u;
            // 0x1ca62c: 0xa022c6ec  sb          $v0, -0x3914($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D72C0u;
    if (runtime->hasFunction(0x1D72C0u)) {
        auto targetFn = runtime->lookupFunction(0x1D72C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA630u; }
        if (ctx->pc != 0x1CA630u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D72C0_0x1d72c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA630u; }
        if (ctx->pc != 0x1CA630u) { return; }
    }
    ctx->pc = 0x1CA630u;
label_1ca630:
    // 0x1ca630: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CA630u;
    {
        const bool branch_taken_0x1ca630 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1CA634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA630u;
            // 0x1ca634: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca630) {
            ctx->pc = 0x1CA668u;
            goto label_1ca668;
        }
    }
    ctx->pc = 0x1CA638u;
    // 0x1ca638: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1ca638u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1ca63c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1ca63cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca640: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1ca640u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca644: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1ca644u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca648: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca648u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca64c: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1ca64cu;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca650: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca650u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca654: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca654u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca658: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca658u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca65c: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca65cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca660: 0x10000279  b           . + 4 + (0x279 << 2)
    ctx->pc = 0x1CA660u;
    {
        const bool branch_taken_0x1ca660 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA660u;
            // 0x1ca664: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca660) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA668u;
label_1ca668:
    // 0x1ca668: 0x8023cc48  lb          $v1, -0x33B8($at)
    ctx->pc = 0x1ca668u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294954056)));
    // 0x1ca66c: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1CA66Cu;
    {
        const bool branch_taken_0x1ca66c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA670u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA66Cu;
            // 0x1ca670: 0x2402000a  addiu       $v0, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca66c) {
            ctx->pc = 0x1CA690u;
            goto label_1ca690;
        }
    }
    ctx->pc = 0x1CA674u;
    // 0x1ca674: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ca674u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ca678: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CA678u;
    {
        const bool branch_taken_0x1ca678 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CA67Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA678u;
            // 0x1ca67c: 0x24020014  addiu       $v0, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca678) {
            ctx->pc = 0x1CA688u;
            goto label_1ca688;
        }
    }
    ctx->pc = 0x1CA680u;
    // 0x1ca680: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1CA680u;
    {
        const bool branch_taken_0x1ca680 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA684u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA680u;
            // 0x1ca684: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca680) {
            ctx->pc = 0x1CA698u;
            goto label_1ca698;
        }
    }
    ctx->pc = 0x1CA688u;
label_1ca688:
    // 0x1ca688: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1CA688u;
    {
        const bool branch_taken_0x1ca688 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA68Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA688u;
            // 0x1ca68c: 0xa2a20000  sb          $v0, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca688) {
            ctx->pc = 0x1CA694u;
            goto label_1ca694;
        }
    }
    ctx->pc = 0x1CA690u;
label_1ca690:
    // 0x1ca690: 0xa2a20000  sb          $v0, 0x0($s5)
    ctx->pc = 0x1ca690u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 2));
label_1ca694:
    // 0x1ca694: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca694u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1ca698:
    // 0x1ca698: 0x1000026c  b           . + 4 + (0x26C << 2)
    ctx->pc = 0x1CA698u;
    {
        const bool branch_taken_0x1ca698 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA69Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA698u;
            // 0x1ca69c: 0xdfbf0080  ld          $ra, 0x80($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca698) {
            ctx->pc = 0x1CB04Cu;
            goto label_1cb04c;
        }
    }
    ctx->pc = 0x1CA6A0u;
label_1ca6a0:
    // 0x1ca6a0: 0xa025c6ee  sb          $a1, -0x3912($at)
    ctx->pc = 0x1ca6a0u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 5));
    // 0x1ca6a4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca6a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca6a8: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1ca6a8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1ca6ac: 0x2841000a  slti        $at, $v0, 0xA
    ctx->pc = 0x1ca6acu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)10) ? 1 : 0);
    // 0x1ca6b0: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CA6B0u;
    {
        const bool branch_taken_0x1ca6b0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ca6b0) {
            ctx->pc = 0x1CA6C0u;
            goto label_1ca6c0;
        }
    }
    ctx->pc = 0x1CA6B8u;
    // 0x1ca6b8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca6b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca6bc: 0xa024c6ec  sb          $a0, -0x3914($at)
    ctx->pc = 0x1ca6bcu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 4));
label_1ca6c0:
    // 0x1ca6c0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca6c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca6c4: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1ca6c4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1ca6c8: 0x8c23c810  lw          $v1, -0x37F0($at)
    ctx->pc = 0x1ca6c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294952976)));
    // 0x1ca6cc: 0x2484b660  addiu       $a0, $a0, -0x49A0
    ctx->pc = 0x1ca6ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948448));
    // 0x1ca6d0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca6d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca6d4: 0x8c22c808  lw          $v0, -0x37F8($at)
    ctx->pc = 0x1ca6d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294952968)));
    // 0x1ca6d8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca6d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca6dc: 0xac23b660  sw          $v1, -0x49A0($at)
    ctx->pc = 0x1ca6dcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294948448), GPR_U32(ctx, 3));
    // 0x1ca6e0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca6e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca6e4: 0xc075cbc  jal         func_1D72F0
    ctx->pc = 0x1CA6E4u;
    SET_GPR_U32(ctx, 31, 0x1CA6ECu);
    ctx->pc = 0x1CA6E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA6E4u;
            // 0x1ca6e8: 0xac22b664  sw          $v0, -0x499C($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294948452), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D72F0u;
    if (runtime->hasFunction(0x1D72F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D72F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA6ECu; }
        if (ctx->pc != 0x1CA6ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D72F0_0x1d72f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA6ECu; }
        if (ctx->pc != 0x1CA6ECu) { return; }
    }
    ctx->pc = 0x1CA6ECu;
label_1ca6ec:
    // 0x1ca6ec: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CA6ECu;
    {
        const bool branch_taken_0x1ca6ec = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1ca6ec) {
            ctx->pc = 0x1CA724u;
            goto label_1ca724;
        }
    }
    ctx->pc = 0x1CA6F4u;
    // 0x1ca6f4: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1ca6f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1ca6f8: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1ca6f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca6fc: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1ca6fcu;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca700: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1ca700u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca704: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca704u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca708: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1ca708u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca70c: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca70cu;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca710: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca710u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca714: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca714u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca718: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca718u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca71c: 0x1000024a  b           . + 4 + (0x24A << 2)
    ctx->pc = 0x1CA71Cu;
    {
        const bool branch_taken_0x1ca71c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA720u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA71Cu;
            // 0x1ca720: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca71c) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA724u;
label_1ca724:
    // 0x1ca724: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1ca724u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1ca728: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca728u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca72c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1ca72cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ca730: 0x10000245  b           . + 4 + (0x245 << 2)
    ctx->pc = 0x1CA730u;
    {
        const bool branch_taken_0x1ca730 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA734u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA730u;
            // 0x1ca734: 0xa2a30000  sb          $v1, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca730) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA738u;
label_1ca738:
    // 0x1ca738: 0xc075ccc  jal         func_1D7330
    ctx->pc = 0x1CA738u;
    SET_GPR_U32(ctx, 31, 0x1CA740u);
    ctx->pc = 0x1CA73Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA738u;
            // 0x1ca73c: 0x9024c820  lbu         $a0, -0x37E0($at) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952992)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7330u;
    if (runtime->hasFunction(0x1D7330u)) {
        auto targetFn = runtime->lookupFunction(0x1D7330u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA740u; }
        if (ctx->pc != 0x1CA740u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7330_0x1d7330(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA740u; }
        if (ctx->pc != 0x1CA740u) { return; }
    }
    ctx->pc = 0x1CA740u;
label_1ca740:
    // 0x1ca740: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CA740u;
    {
        const bool branch_taken_0x1ca740 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1ca740) {
            ctx->pc = 0x1CA778u;
            goto label_1ca778;
        }
    }
    ctx->pc = 0x1CA748u;
    // 0x1ca748: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1ca748u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1ca74c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1ca74cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca750: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1ca750u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca754: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1ca754u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca758: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca758u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca75c: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1ca75cu;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca760: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca760u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca764: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca764u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca768: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca768u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca76c: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca76cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca770: 0x10000235  b           . + 4 + (0x235 << 2)
    ctx->pc = 0x1CA770u;
    {
        const bool branch_taken_0x1ca770 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA774u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA770u;
            // 0x1ca774: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca770) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA778u;
label_1ca778:
    // 0x1ca778: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1ca778u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1ca77c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca77cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca780: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1ca780u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ca784: 0xa2a30000  sb          $v1, 0x0($s5)
    ctx->pc = 0x1ca784u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca788: 0x1000022f  b           . + 4 + (0x22F << 2)
    ctx->pc = 0x1CA788u;
    {
        const bool branch_taken_0x1ca788 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA78Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA788u;
            // 0x1ca78c: 0xa6600000  sh          $zero, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca788) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA790u;
label_1ca790:
    // 0x1ca790: 0x86430000  lh          $v1, 0x0($s2)
    ctx->pc = 0x1ca790u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1ca794: 0x2861001f  slti        $at, $v1, 0x1F
    ctx->pc = 0x1ca794u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x1ca798: 0x1420000d  bnez        $at, . + 4 + (0xD << 2)
    ctx->pc = 0x1CA798u;
    {
        const bool branch_taken_0x1ca798 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ca798) {
            ctx->pc = 0x1CA7D0u;
            goto label_1ca7d0;
        }
    }
    ctx->pc = 0x1CA7A0u;
    // 0x1ca7a0: 0x2402ffaa  addiu       $v0, $zero, -0x56
    ctx->pc = 0x1ca7a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967210));
    // 0x1ca7a4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1ca7a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca7a8: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1ca7a8u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca7ac: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1ca7acu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca7b0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca7b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca7b4: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1ca7b4u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca7b8: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca7b8u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca7bc: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca7bcu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca7c0: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca7c0u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca7c4: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca7c4u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca7c8: 0x1000021f  b           . + 4 + (0x21F << 2)
    ctx->pc = 0x1CA7C8u;
    {
        const bool branch_taken_0x1ca7c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA7CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA7C8u;
            // 0x1ca7cc: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca7c8) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA7D0u;
label_1ca7d0:
    // 0x1ca7d0: 0x86630000  lh          $v1, 0x0($s3)
    ctx->pc = 0x1ca7d0u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1ca7d4: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x1ca7d4u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1ca7d8: 0x0  nop
    ctx->pc = 0x1ca7d8u;
    // NOP
    // 0x1ca7dc: 0x0  nop
    ctx->pc = 0x1ca7dcu;
    // NOP
    // 0x1ca7e0: 0x1010  mfhi        $v0
    ctx->pc = 0x1ca7e0u;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x1ca7e4: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1CA7E4u;
    {
        const bool branch_taken_0x1ca7e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CA7E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA7E4u;
            // 0x1ca7e8: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca7e4) {
            ctx->pc = 0x1CA810u;
            goto label_1ca810;
        }
    }
    ctx->pc = 0x1CA7ECu;
    // 0x1ca7ec: 0x9023c6ee  lbu         $v1, -0x3912($at)
    ctx->pc = 0x1ca7ecu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952686)));
    // 0x1ca7f0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca7f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca7f4: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1ca7f4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1ca7f8: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1ca7f8u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1ca7fc: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CA7FCu;
    {
        const bool branch_taken_0x1ca7fc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ca7fc) {
            ctx->pc = 0x1CA808u;
            goto label_1ca808;
        }
    }
    ctx->pc = 0x1CA804u;
    // 0x1ca804: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1ca804u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1ca808:
    // 0x1ca808: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca808u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca80c: 0xa023c6ec  sb          $v1, -0x3914($at)
    ctx->pc = 0x1ca80cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 3));
label_1ca810:
    // 0x1ca810: 0x86620000  lh          $v0, 0x0($s3)
    ctx->pc = 0x1ca810u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1ca814: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1ca814u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1ca818: 0xc075cd8  jal         func_1D7360
    ctx->pc = 0x1CA818u;
    SET_GPR_U32(ctx, 31, 0x1CA820u);
    ctx->pc = 0x1CA81Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA818u;
            // 0x1ca81c: 0xa6620000  sh          $v0, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7360u;
    if (runtime->hasFunction(0x1D7360u)) {
        auto targetFn = runtime->lookupFunction(0x1D7360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA820u; }
        if (ctx->pc != 0x1CA820u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7360_0x1d7360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA820u; }
        if (ctx->pc != 0x1CA820u) { return; }
    }
    ctx->pc = 0x1CA820u;
label_1ca820:
    // 0x1ca820: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1CA820u;
    {
        const bool branch_taken_0x1ca820 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA824u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA820u;
            // 0x1ca824: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca820) {
            ctx->pc = 0x1CA86Cu;
            goto label_1ca86c;
        }
    }
    ctx->pc = 0x1CA828u;
    // 0x1ca828: 0x24030046  addiu       $v1, $zero, 0x46
    ctx->pc = 0x1ca828u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 70));
    // 0x1ca82c: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1ca82cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1ca830: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca830u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca834: 0xa023c6ee  sb          $v1, -0x3912($at)
    ctx->pc = 0x1ca834u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca838: 0x28410014  slti        $at, $v0, 0x14
    ctx->pc = 0x1ca838u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)20) ? 1 : 0);
    // 0x1ca83c: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CA83Cu;
    {
        const bool branch_taken_0x1ca83c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA840u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA83Cu;
            // 0x1ca840: 0x24020014  addiu       $v0, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca83c) {
            ctx->pc = 0x1CA84Cu;
            goto label_1ca84c;
        }
    }
    ctx->pc = 0x1CA844u;
    // 0x1ca844: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca844u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca848: 0xa022c6ec  sb          $v0, -0x3914($at)
    ctx->pc = 0x1ca848u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 2));
label_1ca84c:
    // 0x1ca84c: 0x82a40000  lb          $a0, 0x0($s5)
    ctx->pc = 0x1ca84cu;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1ca850: 0x24030096  addiu       $v1, $zero, 0x96
    ctx->pc = 0x1ca850u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 150));
    // 0x1ca854: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca854u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca858: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1ca858u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1ca85c: 0xa2a40000  sb          $a0, 0x0($s5)
    ctx->pc = 0x1ca85cu;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1ca860: 0xa6630000  sh          $v1, 0x0($s3)
    ctx->pc = 0x1ca860u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1ca864: 0x100001f8  b           . + 4 + (0x1F8 << 2)
    ctx->pc = 0x1CA864u;
    {
        const bool branch_taken_0x1ca864 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA864u;
            // 0x1ca868: 0xa6200000  sh          $zero, 0x0($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca864) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA86Cu;
label_1ca86c:
    // 0x1ca86c: 0x86620000  lh          $v0, 0x0($s3)
    ctx->pc = 0x1ca86cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1ca870: 0x284101c3  slti        $at, $v0, 0x1C3
    ctx->pc = 0x1ca870u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)451) ? 1 : 0);
    // 0x1ca874: 0x14200015  bnez        $at, . + 4 + (0x15 << 2)
    ctx->pc = 0x1CA874u;
    {
        const bool branch_taken_0x1ca874 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CA878u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA874u;
            // 0x1ca878: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca874) {
            ctx->pc = 0x1CA8CCu;
            goto label_1ca8cc;
        }
    }
    ctx->pc = 0x1CA87Cu;
    // 0x1ca87c: 0x86220000  lh          $v0, 0x0($s1)
    ctx->pc = 0x1ca87cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1ca880: 0x28420003  slti        $v0, $v0, 0x3
    ctx->pc = 0x1ca880u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1ca884: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1CA884u;
    {
        const bool branch_taken_0x1ca884 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CA888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA884u;
            // 0x1ca888: 0x24020063  addiu       $v0, $zero, 0x63 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca884) {
            ctx->pc = 0x1CA8B8u;
            goto label_1ca8b8;
        }
    }
    ctx->pc = 0x1CA88Cu;
    // 0x1ca88c: 0x2403ffae  addiu       $v1, $zero, -0x52
    ctx->pc = 0x1ca88cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1ca890: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1ca890u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca894: 0xa2e30000  sb          $v1, 0x0($s7)
    ctx->pc = 0x1ca894u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca898: 0xa2c20000  sb          $v0, 0x0($s6)
    ctx->pc = 0x1ca898u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca89c: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1ca89cu;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca8a0: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca8a0u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca8a4: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca8a4u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca8a8: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca8a8u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca8ac: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca8acu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca8b0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1CA8B0u;
    {
        const bool branch_taken_0x1ca8b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA8B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA8B0u;
            // 0x1ca8b4: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca8b0) {
            ctx->pc = 0x1CA8C8u;
            goto label_1ca8c8;
        }
    }
    ctx->pc = 0x1CA8B8u;
label_1ca8b8:
    // 0x1ca8b8: 0xa2a20000  sb          $v0, 0x0($s5)
    ctx->pc = 0x1ca8b8u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca8bc: 0x86220000  lh          $v0, 0x0($s1)
    ctx->pc = 0x1ca8bcu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1ca8c0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1ca8c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1ca8c4: 0xa6220000  sh          $v0, 0x0($s1)
    ctx->pc = 0x1ca8c4u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 2));
label_1ca8c8:
    // 0x1ca8c8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca8c8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1ca8cc:
    // 0x1ca8cc: 0x100001de  b           . + 4 + (0x1DE << 2)
    ctx->pc = 0x1CA8CCu;
    {
        const bool branch_taken_0x1ca8cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ca8cc) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA8D4u;
label_1ca8d4:
    // 0x1ca8d4: 0x86430000  lh          $v1, 0x0($s2)
    ctx->pc = 0x1ca8d4u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1ca8d8: 0x2861001f  slti        $at, $v1, 0x1F
    ctx->pc = 0x1ca8d8u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x1ca8dc: 0x1420000d  bnez        $at, . + 4 + (0xD << 2)
    ctx->pc = 0x1CA8DCu;
    {
        const bool branch_taken_0x1ca8dc = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ca8dc) {
            ctx->pc = 0x1CA914u;
            goto label_1ca914;
        }
    }
    ctx->pc = 0x1CA8E4u;
    // 0x1ca8e4: 0x2402ffaa  addiu       $v0, $zero, -0x56
    ctx->pc = 0x1ca8e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967210));
    // 0x1ca8e8: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1ca8e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca8ec: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1ca8ecu;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca8f0: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1ca8f0u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca8f4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca8f4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca8f8: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1ca8f8u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca8fc: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca8fcu;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca900: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca900u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca904: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca904u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca908: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca908u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca90c: 0x100001ce  b           . + 4 + (0x1CE << 2)
    ctx->pc = 0x1CA90Cu;
    {
        const bool branch_taken_0x1ca90c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA90Cu;
            // 0x1ca910: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca90c) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA914u;
label_1ca914:
    // 0x1ca914: 0x86630000  lh          $v1, 0x0($s3)
    ctx->pc = 0x1ca914u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1ca918: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x1ca918u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1ca91c: 0x0  nop
    ctx->pc = 0x1ca91cu;
    // NOP
    // 0x1ca920: 0x0  nop
    ctx->pc = 0x1ca920u;
    // NOP
    // 0x1ca924: 0x1010  mfhi        $v0
    ctx->pc = 0x1ca924u;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x1ca928: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1CA928u;
    {
        const bool branch_taken_0x1ca928 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CA92Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA928u;
            // 0x1ca92c: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca928) {
            ctx->pc = 0x1CA954u;
            goto label_1ca954;
        }
    }
    ctx->pc = 0x1CA930u;
    // 0x1ca930: 0x9023c6ee  lbu         $v1, -0x3912($at)
    ctx->pc = 0x1ca930u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952686)));
    // 0x1ca934: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca934u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca938: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1ca938u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1ca93c: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1ca93cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1ca940: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CA940u;
    {
        const bool branch_taken_0x1ca940 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ca940) {
            ctx->pc = 0x1CA94Cu;
            goto label_1ca94c;
        }
    }
    ctx->pc = 0x1CA948u;
    // 0x1ca948: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1ca948u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1ca94c:
    // 0x1ca94c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca94cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca950: 0xa023c6ec  sb          $v1, -0x3914($at)
    ctx->pc = 0x1ca950u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 3));
label_1ca954:
    // 0x1ca954: 0x86630000  lh          $v1, 0x0($s3)
    ctx->pc = 0x1ca954u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1ca958: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x1ca958u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1ca95c: 0x3082a  slt         $at, $zero, $v1
    ctx->pc = 0x1ca95cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1ca960: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CA960u;
    {
        const bool branch_taken_0x1ca960 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA960u;
            // 0x1ca964: 0xa6620000  sh          $v0, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca960) {
            ctx->pc = 0x1CA970u;
            goto label_1ca970;
        }
    }
    ctx->pc = 0x1CA968u;
    // 0x1ca968: 0x100001b7  b           . + 4 + (0x1B7 << 2)
    ctx->pc = 0x1CA968u;
    {
        const bool branch_taken_0x1ca968 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA96Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA968u;
            // 0x1ca96c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca968) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA970u;
label_1ca970:
    // 0x1ca970: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca970u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca974: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1ca974u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1ca978: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca978u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca97c: 0xa022c6ee  sb          $v0, -0x3912($at)
    ctx->pc = 0x1ca97cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca980: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca980u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca984: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1ca984u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1ca988: 0x28410046  slti        $at, $v0, 0x46
    ctx->pc = 0x1ca988u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)70) ? 1 : 0);
    // 0x1ca98c: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CA98Cu;
    {
        const bool branch_taken_0x1ca98c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA990u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA98Cu;
            // 0x1ca990: 0x24020046  addiu       $v0, $zero, 0x46 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 70));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca98c) {
            ctx->pc = 0x1CA99Cu;
            goto label_1ca99c;
        }
    }
    ctx->pc = 0x1CA994u;
    // 0x1ca994: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca994u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca998: 0xa022c6ec  sb          $v0, -0x3914($at)
    ctx->pc = 0x1ca998u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 2));
label_1ca99c:
    // 0x1ca99c: 0xc07254c  jal         func_1C9530
    ctx->pc = 0x1CA99Cu;
    SET_GPR_U32(ctx, 31, 0x1CA9A4u);
    ctx->pc = 0x1C9530u;
    if (runtime->hasFunction(0x1C9530u)) {
        auto targetFn = runtime->lookupFunction(0x1C9530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA9A4u; }
        if (ctx->pc != 0x1CA9A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C9530_0x1c9530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA9A4u; }
        if (ctx->pc != 0x1CA9A4u) { return; }
    }
    ctx->pc = 0x1CA9A4u;
label_1ca9a4:
    // 0x1ca9a4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca9a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca9a8: 0x8c25c800  lw          $a1, -0x3800($at)
    ctx->pc = 0x1ca9a8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294952960)));
    // 0x1ca9ac: 0xc075d2c  jal         func_1D74B0
    ctx->pc = 0x1CA9ACu;
    SET_GPR_U32(ctx, 31, 0x1CA9B4u);
    ctx->pc = 0x1CA9B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA9ACu;
            // 0x1ca9b0: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D74B0u;
    if (runtime->hasFunction(0x1D74B0u)) {
        auto targetFn = runtime->lookupFunction(0x1D74B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA9B4u; }
        if (ctx->pc != 0x1CA9B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D74B0_0x1d74b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA9B4u; }
        if (ctx->pc != 0x1CA9B4u) { return; }
    }
    ctx->pc = 0x1CA9B4u;
label_1ca9b4:
    // 0x1ca9b4: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CA9B4u;
    {
        const bool branch_taken_0x1ca9b4 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1CA9B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA9B4u;
            // 0x1ca9b8: 0x2403001e  addiu       $v1, $zero, 0x1E (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca9b4) {
            ctx->pc = 0x1CA9ECu;
            goto label_1ca9ec;
        }
    }
    ctx->pc = 0x1CA9BCu;
    // 0x1ca9bc: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1ca9bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1ca9c0: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1ca9c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca9c4: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1ca9c4u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca9c8: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1ca9c8u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca9cc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca9ccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca9d0: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1ca9d0u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca9d4: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca9d4u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca9d8: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca9d8u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca9dc: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca9dcu;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca9e0: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca9e0u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca9e4: 0x10000198  b           . + 4 + (0x198 << 2)
    ctx->pc = 0x1CA9E4u;
    {
        const bool branch_taken_0x1ca9e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA9E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA9E4u;
            // 0x1ca9e8: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca9e4) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA9ECu;
label_1ca9ec:
    // 0x1ca9ec: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca9ecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca9f0: 0x10000195  b           . + 4 + (0x195 << 2)
    ctx->pc = 0x1CA9F0u;
    {
        const bool branch_taken_0x1ca9f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA9F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA9F0u;
            // 0x1ca9f4: 0xa2a30000  sb          $v1, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca9f0) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA9F8u;
label_1ca9f8:
    // 0x1ca9f8: 0xa025c6ee  sb          $a1, -0x3912($at)
    ctx->pc = 0x1ca9f8u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 5));
    // 0x1ca9fc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca9fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1caa00: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1caa00u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1caa04: 0x2841000b  slti        $at, $v0, 0xB
    ctx->pc = 0x1caa04u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)11) ? 1 : 0);
    // 0x1caa08: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CAA08u;
    {
        const bool branch_taken_0x1caa08 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAA0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAA08u;
            // 0x1caa0c: 0x2402000b  addiu       $v0, $zero, 0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caa08) {
            ctx->pc = 0x1CAA18u;
            goto label_1caa18;
        }
    }
    ctx->pc = 0x1CAA10u;
    // 0x1caa10: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1caa10u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1caa14: 0xa022c6ec  sb          $v0, -0x3914($at)
    ctx->pc = 0x1caa14u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 2));
label_1caa18:
    // 0x1caa18: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1caa18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1caa1c: 0xc075ccc  jal         func_1D7330
    ctx->pc = 0x1CAA1Cu;
    SET_GPR_U32(ctx, 31, 0x1CAA24u);
    ctx->pc = 0x1CAA20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAA1Cu;
            // 0x1caa20: 0x9024c820  lbu         $a0, -0x37E0($at) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952992)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7330u;
    if (runtime->hasFunction(0x1D7330u)) {
        auto targetFn = runtime->lookupFunction(0x1D7330u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAA24u; }
        if (ctx->pc != 0x1CAA24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7330_0x1d7330(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAA24u; }
        if (ctx->pc != 0x1CAA24u) { return; }
    }
    ctx->pc = 0x1CAA24u;
label_1caa24:
    // 0x1caa24: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CAA24u;
    {
        const bool branch_taken_0x1caa24 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1caa24) {
            ctx->pc = 0x1CAA5Cu;
            goto label_1caa5c;
        }
    }
    ctx->pc = 0x1CAA2Cu;
    // 0x1caa2c: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1caa2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1caa30: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1caa30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1caa34: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1caa34u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1caa38: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1caa38u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1caa3c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1caa3cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1caa40: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1caa40u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1caa44: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1caa44u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1caa48: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1caa48u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caa4c: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1caa4cu;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caa50: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1caa50u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caa54: 0x1000017c  b           . + 4 + (0x17C << 2)
    ctx->pc = 0x1CAA54u;
    {
        const bool branch_taken_0x1caa54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAA58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAA54u;
            // 0x1caa58: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caa54) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAA5Cu;
label_1caa5c:
    // 0x1caa5c: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1caa5cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1caa60: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1caa60u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1caa64: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1caa64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1caa68: 0xa2a30000  sb          $v1, 0x0($s5)
    ctx->pc = 0x1caa68u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1caa6c: 0x10000176  b           . + 4 + (0x176 << 2)
    ctx->pc = 0x1CAA6Cu;
    {
        const bool branch_taken_0x1caa6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAA70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAA6Cu;
            // 0x1caa70: 0xa6600000  sh          $zero, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caa6c) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAA74u;
label_1caa74:
    // 0x1caa74: 0x86430000  lh          $v1, 0x0($s2)
    ctx->pc = 0x1caa74u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1caa78: 0x2861001f  slti        $at, $v1, 0x1F
    ctx->pc = 0x1caa78u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x1caa7c: 0x1420000d  bnez        $at, . + 4 + (0xD << 2)
    ctx->pc = 0x1CAA7Cu;
    {
        const bool branch_taken_0x1caa7c = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1caa7c) {
            ctx->pc = 0x1CAAB4u;
            goto label_1caab4;
        }
    }
    ctx->pc = 0x1CAA84u;
    // 0x1caa84: 0x2402ffaa  addiu       $v0, $zero, -0x56
    ctx->pc = 0x1caa84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967210));
    // 0x1caa88: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1caa88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1caa8c: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1caa8cu;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1caa90: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1caa90u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1caa94: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1caa94u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1caa98: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1caa98u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1caa9c: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1caa9cu;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1caaa0: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1caaa0u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caaa4: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1caaa4u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caaa8: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1caaa8u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caaac: 0x10000166  b           . + 4 + (0x166 << 2)
    ctx->pc = 0x1CAAACu;
    {
        const bool branch_taken_0x1caaac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAAB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAAACu;
            // 0x1caab0: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caaac) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAAB4u;
label_1caab4:
    // 0x1caab4: 0x86630000  lh          $v1, 0x0($s3)
    ctx->pc = 0x1caab4u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1caab8: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x1caab8u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1caabc: 0x0  nop
    ctx->pc = 0x1caabcu;
    // NOP
    // 0x1caac0: 0x0  nop
    ctx->pc = 0x1caac0u;
    // NOP
    // 0x1caac4: 0x1010  mfhi        $v0
    ctx->pc = 0x1caac4u;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x1caac8: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1CAAC8u;
    {
        const bool branch_taken_0x1caac8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CAACCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAAC8u;
            // 0x1caacc: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caac8) {
            ctx->pc = 0x1CAAF4u;
            goto label_1caaf4;
        }
    }
    ctx->pc = 0x1CAAD0u;
    // 0x1caad0: 0x9023c6ee  lbu         $v1, -0x3912($at)
    ctx->pc = 0x1caad0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952686)));
    // 0x1caad4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1caad4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1caad8: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1caad8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1caadc: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1caadcu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1caae0: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CAAE0u;
    {
        const bool branch_taken_0x1caae0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1caae0) {
            ctx->pc = 0x1CAAECu;
            goto label_1caaec;
        }
    }
    ctx->pc = 0x1CAAE8u;
    // 0x1caae8: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1caae8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1caaec:
    // 0x1caaec: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1caaecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1caaf0: 0xa023c6ec  sb          $v1, -0x3914($at)
    ctx->pc = 0x1caaf0u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 3));
label_1caaf4:
    // 0x1caaf4: 0x86620000  lh          $v0, 0x0($s3)
    ctx->pc = 0x1caaf4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1caaf8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1caaf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1caafc: 0xc075cd8  jal         func_1D7360
    ctx->pc = 0x1CAAFCu;
    SET_GPR_U32(ctx, 31, 0x1CAB04u);
    ctx->pc = 0x1CAB00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAAFCu;
            // 0x1cab00: 0xa6620000  sh          $v0, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7360u;
    if (runtime->hasFunction(0x1D7360u)) {
        auto targetFn = runtime->lookupFunction(0x1D7360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAB04u; }
        if (ctx->pc != 0x1CAB04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7360_0x1d7360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAB04u; }
        if (ctx->pc != 0x1CAB04u) { return; }
    }
    ctx->pc = 0x1CAB04u;
label_1cab04:
    // 0x1cab04: 0x10400010  beqz        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x1CAB04u;
    {
        const bool branch_taken_0x1cab04 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAB08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAB04u;
            // 0x1cab08: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cab04) {
            ctx->pc = 0x1CAB48u;
            goto label_1cab48;
        }
    }
    ctx->pc = 0x1CAB0Cu;
    // 0x1cab0c: 0x2403003c  addiu       $v1, $zero, 0x3C
    ctx->pc = 0x1cab0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x1cab10: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1cab10u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1cab14: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cab14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cab18: 0xa023c6ee  sb          $v1, -0x3912($at)
    ctx->pc = 0x1cab18u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cab1c: 0x28410014  slti        $at, $v0, 0x14
    ctx->pc = 0x1cab1cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)20) ? 1 : 0);
    // 0x1cab20: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CAB20u;
    {
        const bool branch_taken_0x1cab20 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAB24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAB20u;
            // 0x1cab24: 0x24020014  addiu       $v0, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cab20) {
            ctx->pc = 0x1CAB30u;
            goto label_1cab30;
        }
    }
    ctx->pc = 0x1CAB28u;
    // 0x1cab28: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cab28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cab2c: 0xa022c6ec  sb          $v0, -0x3914($at)
    ctx->pc = 0x1cab2cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 2));
label_1cab30:
    // 0x1cab30: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1cab30u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1cab34: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cab34u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cab38: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1cab38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1cab3c: 0xa2a30000  sb          $v1, 0x0($s5)
    ctx->pc = 0x1cab3cu;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cab40: 0x10000141  b           . + 4 + (0x141 << 2)
    ctx->pc = 0x1CAB40u;
    {
        const bool branch_taken_0x1cab40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAB44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAB40u;
            // 0x1cab44: 0xa6600000  sh          $zero, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cab40) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAB48u;
label_1cab48:
    // 0x1cab48: 0x86620000  lh          $v0, 0x0($s3)
    ctx->pc = 0x1cab48u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1cab4c: 0x284101c3  slti        $at, $v0, 0x1C3
    ctx->pc = 0x1cab4cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)451) ? 1 : 0);
    // 0x1cab50: 0x14200015  bnez        $at, . + 4 + (0x15 << 2)
    ctx->pc = 0x1CAB50u;
    {
        const bool branch_taken_0x1cab50 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CAB54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAB50u;
            // 0x1cab54: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cab50) {
            ctx->pc = 0x1CABA8u;
            goto label_1caba8;
        }
    }
    ctx->pc = 0x1CAB58u;
    // 0x1cab58: 0x86220000  lh          $v0, 0x0($s1)
    ctx->pc = 0x1cab58u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cab5c: 0x28420003  slti        $v0, $v0, 0x3
    ctx->pc = 0x1cab5cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1cab60: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1CAB60u;
    {
        const bool branch_taken_0x1cab60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CAB64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAB60u;
            // 0x1cab64: 0x24020063  addiu       $v0, $zero, 0x63 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cab60) {
            ctx->pc = 0x1CAB94u;
            goto label_1cab94;
        }
    }
    ctx->pc = 0x1CAB68u;
    // 0x1cab68: 0x2403ffae  addiu       $v1, $zero, -0x52
    ctx->pc = 0x1cab68u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1cab6c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1cab6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1cab70: 0xa2e30000  sb          $v1, 0x0($s7)
    ctx->pc = 0x1cab70u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cab74: 0xa2c20000  sb          $v0, 0x0($s6)
    ctx->pc = 0x1cab74u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cab78: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1cab78u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cab7c: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1cab7cu;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cab80: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1cab80u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cab84: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1cab84u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cab88: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1cab88u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cab8c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1CAB8Cu;
    {
        const bool branch_taken_0x1cab8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAB90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAB8Cu;
            // 0x1cab90: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cab8c) {
            ctx->pc = 0x1CABA4u;
            goto label_1caba4;
        }
    }
    ctx->pc = 0x1CAB94u;
label_1cab94:
    // 0x1cab94: 0xa2a20000  sb          $v0, 0x0($s5)
    ctx->pc = 0x1cab94u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cab98: 0x86220000  lh          $v0, 0x0($s1)
    ctx->pc = 0x1cab98u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cab9c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1cab9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1caba0: 0xa6220000  sh          $v0, 0x0($s1)
    ctx->pc = 0x1caba0u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 2));
label_1caba4:
    // 0x1caba4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1caba4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1caba8:
    // 0x1caba8: 0x10000127  b           . + 4 + (0x127 << 2)
    ctx->pc = 0x1CABA8u;
    {
        const bool branch_taken_0x1caba8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1caba8) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CABB0u;
label_1cabb0:
    // 0x1cabb0: 0xc075d50  jal         func_1D7540
    ctx->pc = 0x1CABB0u;
    SET_GPR_U32(ctx, 31, 0x1CABB8u);
    ctx->pc = 0x1D7540u;
    if (runtime->hasFunction(0x1D7540u)) {
        auto targetFn = runtime->lookupFunction(0x1D7540u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CABB8u; }
        if (ctx->pc != 0x1CABB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7540_0x1d7540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CABB8u; }
        if (ctx->pc != 0x1CABB8u) { return; }
    }
    ctx->pc = 0x1CABB8u;
label_1cabb8:
    // 0x1cabb8: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CABB8u;
    {
        const bool branch_taken_0x1cabb8 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1CABBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CABB8u;
            // 0x1cabbc: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cabb8) {
            ctx->pc = 0x1CABF0u;
            goto label_1cabf0;
        }
    }
    ctx->pc = 0x1CABC0u;
    // 0x1cabc0: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1cabc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1cabc4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1cabc4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1cabc8: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1cabc8u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cabcc: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1cabccu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cabd0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cabd0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cabd4: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1cabd4u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cabd8: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1cabd8u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cabdc: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1cabdcu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cabe0: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1cabe0u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cabe4: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1cabe4u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cabe8: 0x10000117  b           . + 4 + (0x117 << 2)
    ctx->pc = 0x1CABE8u;
    {
        const bool branch_taken_0x1cabe8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CABECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CABE8u;
            // 0x1cabec: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cabe8) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CABF0u;
label_1cabf0:
    // 0x1cabf0: 0xc075d68  jal         func_1D75A0
    ctx->pc = 0x1CABF0u;
    SET_GPR_U32(ctx, 31, 0x1CABF8u);
    ctx->pc = 0x1CABF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CABF0u;
            // 0x1cabf4: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D75A0u;
    if (runtime->hasFunction(0x1D75A0u)) {
        auto targetFn = runtime->lookupFunction(0x1D75A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CABF8u; }
        if (ctx->pc != 0x1CABF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D75A0_0x1d75a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CABF8u; }
        if (ctx->pc != 0x1CABF8u) { return; }
    }
    ctx->pc = 0x1CABF8u;
label_1cabf8:
    // 0x1cabf8: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CABF8u;
    {
        const bool branch_taken_0x1cabf8 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1cabf8) {
            ctx->pc = 0x1CAC30u;
            goto label_1cac30;
        }
    }
    ctx->pc = 0x1CAC00u;
    // 0x1cac00: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1cac00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1cac04: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1cac04u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1cac08: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1cac08u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cac0c: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1cac0cu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cac10: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cac10u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cac14: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1cac14u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cac18: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1cac18u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cac1c: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1cac1cu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cac20: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1cac20u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cac24: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1cac24u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cac28: 0x10000107  b           . + 4 + (0x107 << 2)
    ctx->pc = 0x1CAC28u;
    {
        const bool branch_taken_0x1cac28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAC2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAC28u;
            // 0x1cac2c: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cac28) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAC30u;
label_1cac30:
    // 0x1cac30: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1cac30u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1cac34: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cac34u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cac38: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1cac38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1cac3c: 0xa2a30000  sb          $v1, 0x0($s5)
    ctx->pc = 0x1cac3cu;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cac40: 0x10000101  b           . + 4 + (0x101 << 2)
    ctx->pc = 0x1CAC40u;
    {
        const bool branch_taken_0x1cac40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAC44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAC40u;
            // 0x1cac44: 0xa6600000  sh          $zero, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cac40) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAC48u;
label_1cac48:
    // 0x1cac48: 0x86430000  lh          $v1, 0x0($s2)
    ctx->pc = 0x1cac48u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1cac4c: 0x2861001f  slti        $at, $v1, 0x1F
    ctx->pc = 0x1cac4cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x1cac50: 0x1420000f  bnez        $at, . + 4 + (0xF << 2)
    ctx->pc = 0x1CAC50u;
    {
        const bool branch_taken_0x1cac50 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cac50) {
            ctx->pc = 0x1CAC90u;
            goto label_1cac90;
        }
    }
    ctx->pc = 0x1CAC58u;
    // 0x1cac58: 0xc075d5c  jal         func_1D7570
    ctx->pc = 0x1CAC58u;
    SET_GPR_U32(ctx, 31, 0x1CAC60u);
    ctx->pc = 0x1D7570u;
    if (runtime->hasFunction(0x1D7570u)) {
        auto targetFn = runtime->lookupFunction(0x1D7570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAC60u; }
        if (ctx->pc != 0x1CAC60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7570_0x1d7570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAC60u; }
        if (ctx->pc != 0x1CAC60u) { return; }
    }
    ctx->pc = 0x1CAC60u;
label_1cac60:
    // 0x1cac60: 0x2402ffaa  addiu       $v0, $zero, -0x56
    ctx->pc = 0x1cac60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967210));
    // 0x1cac64: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1cac64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1cac68: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1cac68u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cac6c: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1cac6cu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cac70: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cac70u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cac74: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1cac74u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cac78: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1cac78u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cac7c: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1cac7cu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cac80: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1cac80u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cac84: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1cac84u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cac88: 0x100000ef  b           . + 4 + (0xEF << 2)
    ctx->pc = 0x1CAC88u;
    {
        const bool branch_taken_0x1cac88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAC8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAC88u;
            // 0x1cac8c: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cac88) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAC90u;
label_1cac90:
    // 0x1cac90: 0x86630000  lh          $v1, 0x0($s3)
    ctx->pc = 0x1cac90u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1cac94: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x1cac94u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1cac98: 0x0  nop
    ctx->pc = 0x1cac98u;
    // NOP
    // 0x1cac9c: 0x0  nop
    ctx->pc = 0x1cac9cu;
    // NOP
    // 0x1caca0: 0x1010  mfhi        $v0
    ctx->pc = 0x1caca0u;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x1caca4: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1CACA4u;
    {
        const bool branch_taken_0x1caca4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CACA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CACA4u;
            // 0x1caca8: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caca4) {
            ctx->pc = 0x1CACD0u;
            goto label_1cacd0;
        }
    }
    ctx->pc = 0x1CACACu;
    // 0x1cacac: 0x9023c6ee  lbu         $v1, -0x3912($at)
    ctx->pc = 0x1cacacu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952686)));
    // 0x1cacb0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cacb0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cacb4: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1cacb4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1cacb8: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1cacb8u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1cacbc: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CACBCu;
    {
        const bool branch_taken_0x1cacbc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cacbc) {
            ctx->pc = 0x1CACC8u;
            goto label_1cacc8;
        }
    }
    ctx->pc = 0x1CACC4u;
    // 0x1cacc4: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1cacc4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1cacc8:
    // 0x1cacc8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cacc8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1caccc: 0xa023c6ec  sb          $v1, -0x3914($at)
    ctx->pc = 0x1cacccu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 3));
label_1cacd0:
    // 0x1cacd0: 0x86620000  lh          $v0, 0x0($s3)
    ctx->pc = 0x1cacd0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1cacd4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1cacd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1cacd8: 0xc075d74  jal         func_1D75D0
    ctx->pc = 0x1CACD8u;
    SET_GPR_U32(ctx, 31, 0x1CACE0u);
    ctx->pc = 0x1CACDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CACD8u;
            // 0x1cacdc: 0xa6620000  sh          $v0, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D75D0u;
    if (runtime->hasFunction(0x1D75D0u)) {
        auto targetFn = runtime->lookupFunction(0x1D75D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CACE0u; }
        if (ctx->pc != 0x1CACE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D75D0_0x1d75d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CACE0u; }
        if (ctx->pc != 0x1CACE0u) { return; }
    }
    ctx->pc = 0x1CACE0u;
label_1cace0:
    // 0x1cace0: 0x441001b  bgez        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1CACE0u;
    {
        const bool branch_taken_0x1cace0 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1CACE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CACE0u;
            // 0x1cace4: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cace0) {
            ctx->pc = 0x1CAD50u;
            goto label_1cad50;
        }
    }
    ctx->pc = 0x1CACE8u;
    // 0x1cace8: 0x86220000  lh          $v0, 0x0($s1)
    ctx->pc = 0x1cace8u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cacec: 0x28420003  slti        $v0, $v0, 0x3
    ctx->pc = 0x1cacecu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1cacf0: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1CACF0u;
    {
        const bool branch_taken_0x1cacf0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cacf0) {
            ctx->pc = 0x1CAD2Cu;
            goto label_1cad2c;
        }
    }
    ctx->pc = 0x1CACF8u;
    // 0x1cacf8: 0xc075d5c  jal         func_1D7570
    ctx->pc = 0x1CACF8u;
    SET_GPR_U32(ctx, 31, 0x1CAD00u);
    ctx->pc = 0x1D7570u;
    if (runtime->hasFunction(0x1D7570u)) {
        auto targetFn = runtime->lookupFunction(0x1D7570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAD00u; }
        if (ctx->pc != 0x1CAD00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7570_0x1d7570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAD00u; }
        if (ctx->pc != 0x1CAD00u) { return; }
    }
    ctx->pc = 0x1CAD00u;
label_1cad00:
    // 0x1cad00: 0x2403ffac  addiu       $v1, $zero, -0x54
    ctx->pc = 0x1cad00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967212));
    // 0x1cad04: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1cad04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1cad08: 0xa2e30000  sb          $v1, 0x0($s7)
    ctx->pc = 0x1cad08u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cad0c: 0xa2c20000  sb          $v0, 0x0($s6)
    ctx->pc = 0x1cad0cu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cad10: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1cad10u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cad14: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1cad14u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cad18: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1cad18u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cad1c: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1cad1cu;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cad20: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1cad20u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cad24: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1CAD24u;
    {
        const bool branch_taken_0x1cad24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAD28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAD24u;
            // 0x1cad28: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cad24) {
            ctx->pc = 0x1CAD48u;
            goto label_1cad48;
        }
    }
    ctx->pc = 0x1CAD2Cu;
label_1cad2c:
    // 0x1cad2c: 0xc075d5c  jal         func_1D7570
    ctx->pc = 0x1CAD2Cu;
    SET_GPR_U32(ctx, 31, 0x1CAD34u);
    ctx->pc = 0x1D7570u;
    if (runtime->hasFunction(0x1D7570u)) {
        auto targetFn = runtime->lookupFunction(0x1D7570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAD34u; }
        if (ctx->pc != 0x1CAD34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7570_0x1d7570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAD34u; }
        if (ctx->pc != 0x1CAD34u) { return; }
    }
    ctx->pc = 0x1CAD34u;
label_1cad34:
    // 0x1cad34: 0x24020063  addiu       $v0, $zero, 0x63
    ctx->pc = 0x1cad34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1cad38: 0xa2a20000  sb          $v0, 0x0($s5)
    ctx->pc = 0x1cad38u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cad3c: 0x86220000  lh          $v0, 0x0($s1)
    ctx->pc = 0x1cad3cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cad40: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1cad40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1cad44: 0xa6220000  sh          $v0, 0x0($s1)
    ctx->pc = 0x1cad44u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 2));
label_1cad48:
    // 0x1cad48: 0x100000bf  b           . + 4 + (0xBF << 2)
    ctx->pc = 0x1CAD48u;
    {
        const bool branch_taken_0x1cad48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAD4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAD48u;
            // 0x1cad4c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cad48) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAD50u;
label_1cad50:
    // 0x1cad50: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CAD50u;
    {
        const bool branch_taken_0x1cad50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1CAD54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAD50u;
            // 0x1cad54: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cad50) {
            ctx->pc = 0x1CAD60u;
            goto label_1cad60;
        }
    }
    ctx->pc = 0x1CAD58u;
    // 0x1cad58: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1CAD58u;
    {
        const bool branch_taken_0x1cad58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAD5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAD58u;
            // 0x1cad5c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cad58) {
            ctx->pc = 0x1CADD4u;
            goto label_1cadd4;
        }
    }
    ctx->pc = 0x1CAD60u;
label_1cad60:
    // 0x1cad60: 0x24030046  addiu       $v1, $zero, 0x46
    ctx->pc = 0x1cad60u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 70));
    // 0x1cad64: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1cad64u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1cad68: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cad68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cad6c: 0xa023c6ee  sb          $v1, -0x3912($at)
    ctx->pc = 0x1cad6cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cad70: 0x2841003c  slti        $at, $v0, 0x3C
    ctx->pc = 0x1cad70u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)60) ? 1 : 0);
    // 0x1cad74: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1CAD74u;
    {
        const bool branch_taken_0x1cad74 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAD78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAD74u;
            // 0x1cad78: 0x3c040034  lui         $a0, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cad74) {
            ctx->pc = 0x1CAD88u;
            goto label_1cad88;
        }
    }
    ctx->pc = 0x1CAD7Cu;
    // 0x1cad7c: 0x2402003c  addiu       $v0, $zero, 0x3C
    ctx->pc = 0x1cad7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x1cad80: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cad80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cad84: 0xa022c6ec  sb          $v0, -0x3914($at)
    ctx->pc = 0x1cad84u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 2));
label_1cad88:
    // 0x1cad88: 0xc075d80  jal         func_1D7600
    ctx->pc = 0x1CAD88u;
    SET_GPR_U32(ctx, 31, 0x1CAD90u);
    ctx->pc = 0x1CAD8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAD88u;
            // 0x1cad8c: 0x2484b660  addiu       $a0, $a0, -0x49A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948448));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7600u;
    if (runtime->hasFunction(0x1D7600u)) {
        auto targetFn = runtime->lookupFunction(0x1D7600u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAD90u; }
        if (ctx->pc != 0x1CAD90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7600_0x1d7600(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAD90u; }
        if (ctx->pc != 0x1CAD90u) { return; }
    }
    ctx->pc = 0x1CAD90u;
label_1cad90:
    // 0x1cad90: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cad90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cad94: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cad94u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cad98: 0x8c23b660  lw          $v1, -0x49A0($at)
    ctx->pc = 0x1cad98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294948448)));
    // 0x1cad9c: 0x2484b660  addiu       $a0, $a0, -0x49A0
    ctx->pc = 0x1cad9cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948448));
    // 0x1cada0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cada0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cada4: 0x8c22b664  lw          $v0, -0x499C($at)
    ctx->pc = 0x1cada4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294948452)));
    // 0x1cada8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cada8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cadac: 0xac23c810  sw          $v1, -0x37F0($at)
    ctx->pc = 0x1cadacu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294952976), GPR_U32(ctx, 3));
    // 0x1cadb0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cadb0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cadb4: 0xc075cbc  jal         func_1D72F0
    ctx->pc = 0x1CADB4u;
    SET_GPR_U32(ctx, 31, 0x1CADBCu);
    ctx->pc = 0x1CADB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CADB4u;
            // 0x1cadb8: 0xac22c808  sw          $v0, -0x37F8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294952968), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D72F0u;
    if (runtime->hasFunction(0x1D72F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D72F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CADBCu; }
        if (ctx->pc != 0x1CADBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D72F0_0x1d72f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CADBCu; }
        if (ctx->pc != 0x1CADBCu) { return; }
    }
    ctx->pc = 0x1CADBCu;
label_1cadbc:
    // 0x1cadbc: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1cadbcu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1cadc0: 0x2402005a  addiu       $v0, $zero, 0x5A
    ctx->pc = 0x1cadc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 90));
    // 0x1cadc4: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1cadc4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1cadc8: 0xa2a30000  sb          $v1, 0x0($s5)
    ctx->pc = 0x1cadc8u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cadcc: 0xa6620000  sh          $v0, 0x0($s3)
    ctx->pc = 0x1cadccu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1cadd0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cadd0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cadd4:
    // 0x1cadd4: 0x1000009c  b           . + 4 + (0x9C << 2)
    ctx->pc = 0x1CADD4u;
    {
        const bool branch_taken_0x1cadd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cadd4) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CADDCu;
label_1caddc:
    // 0x1caddc: 0x86630000  lh          $v1, 0x0($s3)
    ctx->pc = 0x1caddcu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1cade0: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x1cade0u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1cade4: 0x0  nop
    ctx->pc = 0x1cade4u;
    // NOP
    // 0x1cade8: 0x0  nop
    ctx->pc = 0x1cade8u;
    // NOP
    // 0x1cadec: 0x1010  mfhi        $v0
    ctx->pc = 0x1cadecu;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x1cadf0: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1CADF0u;
    {
        const bool branch_taken_0x1cadf0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CADF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CADF0u;
            // 0x1cadf4: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cadf0) {
            ctx->pc = 0x1CAE1Cu;
            goto label_1cae1c;
        }
    }
    ctx->pc = 0x1CADF8u;
    // 0x1cadf8: 0x9023c6ee  lbu         $v1, -0x3912($at)
    ctx->pc = 0x1cadf8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952686)));
    // 0x1cadfc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cadfcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cae00: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1cae00u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1cae04: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1cae04u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1cae08: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CAE08u;
    {
        const bool branch_taken_0x1cae08 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cae08) {
            ctx->pc = 0x1CAE14u;
            goto label_1cae14;
        }
    }
    ctx->pc = 0x1CAE10u;
    // 0x1cae10: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1cae10u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1cae14:
    // 0x1cae14: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cae14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cae18: 0xa023c6ec  sb          $v1, -0x3914($at)
    ctx->pc = 0x1cae18u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 3));
label_1cae1c:
    // 0x1cae1c: 0x86620000  lh          $v0, 0x0($s3)
    ctx->pc = 0x1cae1cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1cae20: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1cae20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1cae24: 0xa6620000  sh          $v0, 0x0($s3)
    ctx->pc = 0x1cae24u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1cae28: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1cae28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1cae2c: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1cae2cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1cae30: 0x2082a  slt         $at, $zero, $v0
    ctx->pc = 0x1cae30u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1cae34: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CAE34u;
    {
        const bool branch_taken_0x1cae34 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAE38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAE34u;
            // 0x1cae38: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cae34) {
            ctx->pc = 0x1CAE44u;
            goto label_1cae44;
        }
    }
    ctx->pc = 0x1CAE3Cu;
    // 0x1cae3c: 0x10000082  b           . + 4 + (0x82 << 2)
    ctx->pc = 0x1CAE3Cu;
    {
        const bool branch_taken_0x1cae3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cae3c) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAE44u;
label_1cae44:
    // 0x1cae44: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1cae44u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cae48: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1cae48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1cae4c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cae4cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cae50: 0xa022c6ee  sb          $v0, -0x3912($at)
    ctx->pc = 0x1cae50u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cae54: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cae54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cae58: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1cae58u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1cae5c: 0x28410046  slti        $at, $v0, 0x46
    ctx->pc = 0x1cae5cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)70) ? 1 : 0);
    // 0x1cae60: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CAE60u;
    {
        const bool branch_taken_0x1cae60 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAE64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAE60u;
            // 0x1cae64: 0x24020046  addiu       $v0, $zero, 0x46 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 70));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cae60) {
            ctx->pc = 0x1CAE70u;
            goto label_1cae70;
        }
    }
    ctx->pc = 0x1CAE68u;
    // 0x1cae68: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cae68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cae6c: 0xa022c6ec  sb          $v0, -0x3914($at)
    ctx->pc = 0x1cae6cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 2));
label_1cae70:
    // 0x1cae70: 0xc07254c  jal         func_1C9530
    ctx->pc = 0x1CAE70u;
    SET_GPR_U32(ctx, 31, 0x1CAE78u);
    ctx->pc = 0x1C9530u;
    if (runtime->hasFunction(0x1C9530u)) {
        auto targetFn = runtime->lookupFunction(0x1C9530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAE78u; }
        if (ctx->pc != 0x1CAE78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C9530_0x1c9530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAE78u; }
        if (ctx->pc != 0x1CAE78u) { return; }
    }
    ctx->pc = 0x1CAE78u;
label_1cae78:
    // 0x1cae78: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cae78u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cae7c: 0xc075d98  jal         func_1D7660
    ctx->pc = 0x1CAE7Cu;
    SET_GPR_U32(ctx, 31, 0x1CAE84u);
    ctx->pc = 0x1CAE80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAE7Cu;
            // 0x1cae80: 0x2484b660  addiu       $a0, $a0, -0x49A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948448));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7660u;
    if (runtime->hasFunction(0x1D7660u)) {
        auto targetFn = runtime->lookupFunction(0x1D7660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAE84u; }
        if (ctx->pc != 0x1CAE84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7660_0x1d7660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAE84u; }
        if (ctx->pc != 0x1CAE84u) { return; }
    }
    ctx->pc = 0x1CAE84u;
label_1cae84:
    // 0x1cae84: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CAE84u;
    {
        const bool branch_taken_0x1cae84 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1CAE88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAE84u;
            // 0x1cae88: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cae84) {
            ctx->pc = 0x1CAEBCu;
            goto label_1caebc;
        }
    }
    ctx->pc = 0x1CAE8Cu;
    // 0x1cae8c: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1cae8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1cae90: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1cae90u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1cae94: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1cae94u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cae98: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1cae98u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cae9c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cae9cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1caea0: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1caea0u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1caea4: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1caea4u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1caea8: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1caea8u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caeac: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1caeacu;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caeb0: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1caeb0u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caeb4: 0x10000064  b           . + 4 + (0x64 << 2)
    ctx->pc = 0x1CAEB4u;
    {
        const bool branch_taken_0x1caeb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAEB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAEB4u;
            // 0x1caeb8: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caeb4) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAEBCu;
label_1caebc:
    // 0x1caebc: 0x8c22b660  lw          $v0, -0x49A0($at)
    ctx->pc = 0x1caebcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294948448)));
    // 0x1caec0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1caec0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1caec4: 0xac22c800  sw          $v0, -0x3800($at)
    ctx->pc = 0x1caec4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294952960), GPR_U32(ctx, 2));
    // 0x1caec8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1caec8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1caecc: 0x8c25c800  lw          $a1, -0x3800($at)
    ctx->pc = 0x1caeccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294952960)));
    // 0x1caed0: 0xc075d2c  jal         func_1D74B0
    ctx->pc = 0x1CAED0u;
    SET_GPR_U32(ctx, 31, 0x1CAED8u);
    ctx->pc = 0x1CAED4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAED0u;
            // 0x1caed4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D74B0u;
    if (runtime->hasFunction(0x1D74B0u)) {
        auto targetFn = runtime->lookupFunction(0x1D74B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAED8u; }
        if (ctx->pc != 0x1CAED8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D74B0_0x1d74b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAED8u; }
        if (ctx->pc != 0x1CAED8u) { return; }
    }
    ctx->pc = 0x1CAED8u;
label_1caed8:
    // 0x1caed8: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CAED8u;
    {
        const bool branch_taken_0x1caed8 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1CAEDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAED8u;
            // 0x1caedc: 0x2403001e  addiu       $v1, $zero, 0x1E (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caed8) {
            ctx->pc = 0x1CAF10u;
            goto label_1caf10;
        }
    }
    ctx->pc = 0x1CAEE0u;
    // 0x1caee0: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1caee0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1caee4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1caee4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1caee8: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1caee8u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1caeec: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1caeecu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1caef0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1caef0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1caef4: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1caef4u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1caef8: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1caef8u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1caefc: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1caefcu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caf00: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1caf00u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caf04: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1caf04u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caf08: 0x1000004f  b           . + 4 + (0x4F << 2)
    ctx->pc = 0x1CAF08u;
    {
        const bool branch_taken_0x1caf08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAF0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAF08u;
            // 0x1caf0c: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caf08) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAF10u;
label_1caf10:
    // 0x1caf10: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1caf10u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1caf14: 0x1000004c  b           . + 4 + (0x4C << 2)
    ctx->pc = 0x1CAF14u;
    {
        const bool branch_taken_0x1caf14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAF18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAF14u;
            // 0x1caf18: 0xa2a30000  sb          $v1, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caf14) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAF1Cu;
label_1caf1c:
    // 0x1caf1c: 0xc075ce4  jal         func_1D7390
    ctx->pc = 0x1CAF1Cu;
    SET_GPR_U32(ctx, 31, 0x1CAF24u);
    ctx->pc = 0x1D7390u;
    if (runtime->hasFunction(0x1D7390u)) {
        auto targetFn = runtime->lookupFunction(0x1D7390u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAF24u; }
        if (ctx->pc != 0x1CAF24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7390_0x1d7390(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAF24u; }
        if (ctx->pc != 0x1CAF24u) { return; }
    }
    ctx->pc = 0x1CAF24u;
label_1caf24:
    // 0x1caf24: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1caf24u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1caf28: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1caf28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1caf2c: 0x2484b668  addiu       $a0, $a0, -0x4998
    ctx->pc = 0x1caf2cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948456));
    // 0x1caf30: 0xc075d00  jal         func_1D7400
    ctx->pc = 0x1CAF30u;
    SET_GPR_U32(ctx, 31, 0x1CAF38u);
    ctx->pc = 0x1CAF34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAF30u;
            // 0x1caf34: 0xac20b668  sw          $zero, -0x4998($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294948456), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7400u;
    if (runtime->hasFunction(0x1D7400u)) {
        auto targetFn = runtime->lookupFunction(0x1D7400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAF38u; }
        if (ctx->pc != 0x1CAF38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7400_0x1d7400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAF38u; }
        if (ctx->pc != 0x1CAF38u) { return; }
    }
    ctx->pc = 0x1CAF38u;
label_1caf38:
    // 0x1caf38: 0x4400004  bltz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1CAF38u;
    {
        const bool branch_taken_0x1caf38 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1CAF3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAF38u;
            // 0x1caf3c: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caf38) {
            ctx->pc = 0x1CAF4Cu;
            goto label_1caf4c;
        }
    }
    ctx->pc = 0x1CAF40u;
    // 0x1caf40: 0x8c22b668  lw          $v0, -0x4998($at)
    ctx->pc = 0x1caf40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294948456)));
    // 0x1caf44: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CAF44u;
    {
        const bool branch_taken_0x1caf44 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CAF48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAF44u;
            // 0x1caf48: 0x24030064  addiu       $v1, $zero, 0x64 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caf44) {
            ctx->pc = 0x1CAF7Cu;
            goto label_1caf7c;
        }
    }
    ctx->pc = 0x1CAF4Cu;
label_1caf4c:
    // 0x1caf4c: 0x2402ffad  addiu       $v0, $zero, -0x53
    ctx->pc = 0x1caf4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967213));
    // 0x1caf50: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1caf50u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1caf54: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1caf54u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1caf58: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1caf58u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1caf5c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1caf5cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1caf60: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1caf60u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1caf64: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1caf64u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1caf68: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1caf68u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caf6c: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1caf6cu;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caf70: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1caf70u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caf74: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x1CAF74u;
    {
        const bool branch_taken_0x1caf74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAF78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAF74u;
            // 0x1caf78: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caf74) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAF7Cu;
label_1caf7c:
    // 0x1caf7c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1caf7cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1caf80: 0xa023c6ee  sb          $v1, -0x3912($at)
    ctx->pc = 0x1caf80u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 3));
    // 0x1caf84: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1caf84u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1caf88: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1caf88u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1caf8c: 0xa023c6ec  sb          $v1, -0x3914($at)
    ctx->pc = 0x1caf8cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 3));
    // 0x1caf90: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1caf90u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1caf94: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1caf94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1caf98: 0xa2a30000  sb          $v1, 0x0($s5)
    ctx->pc = 0x1caf98u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1caf9c: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1caf9cu;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cafa0: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1cafa0u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cafa4: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1cafa4u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cafa8: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1cafa8u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cafac: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1CAFACu;
    {
        const bool branch_taken_0x1cafac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAFB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAFACu;
            // 0x1cafb0: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cafac) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAFB4u;
label_1cafb4:
    // 0x1cafb4: 0x9022c6ed  lbu         $v0, -0x3913($at)
    ctx->pc = 0x1cafb4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952685)));
    // 0x1cafb8: 0x14440009  bne         $v0, $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1CAFB8u;
    {
        const bool branch_taken_0x1cafb8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x1CAFBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAFB8u;
            // 0x1cafbc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cafb8) {
            ctx->pc = 0x1CAFE0u;
            goto label_1cafe0;
        }
    }
    ctx->pc = 0x1CAFC0u;
    // 0x1cafc0: 0xa2c00000  sb          $zero, 0x0($s6)
    ctx->pc = 0x1cafc0u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cafc4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1cafc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1cafc8: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1cafc8u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cafcc: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1cafccu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cafd0: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1cafd0u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cafd4: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1cafd4u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cafd8: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x1CAFD8u;
    {
        const bool branch_taken_0x1cafd8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAFDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAFD8u;
            // 0x1cafdc: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cafd8) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAFE0u;
label_1cafe0:
    // 0x1cafe0: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1CAFE0u;
    {
        const bool branch_taken_0x1cafe0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cafe0) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAFE8u;
label_1cafe8:
    // 0x1cafe8: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1cafe8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1cafec: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cafecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1caff0: 0xa2a30000  sb          $v1, 0x0($s5)
    ctx->pc = 0x1caff0u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1caff4: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1caff4u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1caff8: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1CAFF8u;
    {
        const bool branch_taken_0x1caff8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAFFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAFF8u;
            // 0x1caffc: 0xa6600000  sh          $zero, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caff8) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CB000u;
label_1cb000:
    // 0x1cb000: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1cb000u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb004: 0xc072c60  jal         func_1CB180
    ctx->pc = 0x1CB004u;
    SET_GPR_U32(ctx, 31, 0x1CB00Cu);
    ctx->pc = 0x1CB008u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB004u;
            // 0x1cb008: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CB180u;
    if (runtime->hasFunction(0x1CB180u)) {
        auto targetFn = runtime->lookupFunction(0x1CB180u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB00Cu; }
        if (ctx->pc != 0x1CB00Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CB180_0x1cb180(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB00Cu; }
        if (ctx->pc != 0x1CB00Cu) { return; }
    }
    ctx->pc = 0x1CB00Cu;
label_1cb00c:
    // 0x1cb00c: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CB00Cu;
    {
        const bool branch_taken_0x1cb00c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB010u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB00Cu;
            // 0x1cb010: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb00c) {
            ctx->pc = 0x1CB044u;
            goto label_1cb044;
        }
    }
    ctx->pc = 0x1CB014u;
    // 0x1cb014: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x1cb014u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1cb018: 0xa020c6ec  sb          $zero, -0x3914($at)
    ctx->pc = 0x1cb018u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cb01c: 0x2403005a  addiu       $v1, $zero, 0x5A
    ctx->pc = 0x1cb01cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 90));
    // 0x1cb020: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb020u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb024: 0xa022c6ee  sb          $v0, -0x3912($at)
    ctx->pc = 0x1cb024u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cb028: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cb028u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cb02c: 0xa2a20000  sb          $v0, 0x0($s5)
    ctx->pc = 0x1cb02cu;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cb030: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1cb030u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cb034: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1cb034u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1cb038: 0xa6630000  sh          $v1, 0x0($s3)
    ctx->pc = 0x1cb038u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1cb03c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1CB03Cu;
    {
        const bool branch_taken_0x1cb03c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB040u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB03Cu;
            // 0x1cb040: 0xa6400000  sh          $zero, 0x0($s2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb03c) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CB044u;
label_1cb044:
    // 0x1cb044: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cb044u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cb048:
    // 0x1cb048: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x1cb048u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
label_1cb04c:
    // 0x1cb04c: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x1cb04cu;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1cb050: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1cb050u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1cb054: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1cb054u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1cb058: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1cb058u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1cb05c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1cb05cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1cb060: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1cb060u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cb064: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cb064u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cb068: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cb068u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cb06c: 0x3e00008  jr          $ra
    ctx->pc = 0x1CB06Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CB070u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB06Cu;
            // 0x1cb070: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CA43Cu: goto label_1ca43c;
            case 0x1CA474u: goto label_1ca474;
            case 0x1CA490u: goto label_1ca490;
            case 0x1CA558u: goto label_1ca558;
            case 0x1CA57Cu: goto label_1ca57c;
            case 0x1CA598u: goto label_1ca598;
            case 0x1CA5C0u: goto label_1ca5c0;
            case 0x1CA5D8u: goto label_1ca5d8;
            case 0x1CA610u: goto label_1ca610;
            case 0x1CA624u: goto label_1ca624;
            case 0x1CA630u: goto label_1ca630;
            case 0x1CA668u: goto label_1ca668;
            case 0x1CA688u: goto label_1ca688;
            case 0x1CA690u: goto label_1ca690;
            case 0x1CA694u: goto label_1ca694;
            case 0x1CA698u: goto label_1ca698;
            case 0x1CA6A0u: goto label_1ca6a0;
            case 0x1CA6C0u: goto label_1ca6c0;
            case 0x1CA6ECu: goto label_1ca6ec;
            case 0x1CA724u: goto label_1ca724;
            case 0x1CA738u: goto label_1ca738;
            case 0x1CA740u: goto label_1ca740;
            case 0x1CA778u: goto label_1ca778;
            case 0x1CA790u: goto label_1ca790;
            case 0x1CA7D0u: goto label_1ca7d0;
            case 0x1CA808u: goto label_1ca808;
            case 0x1CA810u: goto label_1ca810;
            case 0x1CA820u: goto label_1ca820;
            case 0x1CA84Cu: goto label_1ca84c;
            case 0x1CA86Cu: goto label_1ca86c;
            case 0x1CA8B8u: goto label_1ca8b8;
            case 0x1CA8C8u: goto label_1ca8c8;
            case 0x1CA8CCu: goto label_1ca8cc;
            case 0x1CA8D4u: goto label_1ca8d4;
            case 0x1CA914u: goto label_1ca914;
            case 0x1CA94Cu: goto label_1ca94c;
            case 0x1CA954u: goto label_1ca954;
            case 0x1CA970u: goto label_1ca970;
            case 0x1CA99Cu: goto label_1ca99c;
            case 0x1CA9A4u: goto label_1ca9a4;
            case 0x1CA9B4u: goto label_1ca9b4;
            case 0x1CA9ECu: goto label_1ca9ec;
            case 0x1CA9F8u: goto label_1ca9f8;
            case 0x1CAA18u: goto label_1caa18;
            case 0x1CAA24u: goto label_1caa24;
            case 0x1CAA5Cu: goto label_1caa5c;
            case 0x1CAA74u: goto label_1caa74;
            case 0x1CAAB4u: goto label_1caab4;
            case 0x1CAAECu: goto label_1caaec;
            case 0x1CAAF4u: goto label_1caaf4;
            case 0x1CAB04u: goto label_1cab04;
            case 0x1CAB30u: goto label_1cab30;
            case 0x1CAB48u: goto label_1cab48;
            case 0x1CAB94u: goto label_1cab94;
            case 0x1CABA4u: goto label_1caba4;
            case 0x1CABA8u: goto label_1caba8;
            case 0x1CABB0u: goto label_1cabb0;
            case 0x1CABB8u: goto label_1cabb8;
            case 0x1CABF0u: goto label_1cabf0;
            case 0x1CABF8u: goto label_1cabf8;
            case 0x1CAC30u: goto label_1cac30;
            case 0x1CAC48u: goto label_1cac48;
            case 0x1CAC60u: goto label_1cac60;
            case 0x1CAC90u: goto label_1cac90;
            case 0x1CACC8u: goto label_1cacc8;
            case 0x1CACD0u: goto label_1cacd0;
            case 0x1CACE0u: goto label_1cace0;
            case 0x1CAD00u: goto label_1cad00;
            case 0x1CAD2Cu: goto label_1cad2c;
            case 0x1CAD34u: goto label_1cad34;
            case 0x1CAD48u: goto label_1cad48;
            case 0x1CAD50u: goto label_1cad50;
            case 0x1CAD60u: goto label_1cad60;
            case 0x1CAD88u: goto label_1cad88;
            case 0x1CAD90u: goto label_1cad90;
            case 0x1CADBCu: goto label_1cadbc;
            case 0x1CADD4u: goto label_1cadd4;
            case 0x1CADDCu: goto label_1caddc;
            case 0x1CAE14u: goto label_1cae14;
            case 0x1CAE1Cu: goto label_1cae1c;
            case 0x1CAE44u: goto label_1cae44;
            case 0x1CAE70u: goto label_1cae70;
            case 0x1CAE78u: goto label_1cae78;
            case 0x1CAE84u: goto label_1cae84;
            case 0x1CAEBCu: goto label_1caebc;
            case 0x1CAED8u: goto label_1caed8;
            case 0x1CAF10u: goto label_1caf10;
            case 0x1CAF1Cu: goto label_1caf1c;
            case 0x1CAF24u: goto label_1caf24;
            case 0x1CAF38u: goto label_1caf38;
            case 0x1CAF4Cu: goto label_1caf4c;
            case 0x1CAF7Cu: goto label_1caf7c;
            case 0x1CAFB4u: goto label_1cafb4;
            case 0x1CAFE0u: goto label_1cafe0;
            case 0x1CAFE8u: goto label_1cafe8;
            case 0x1CB000u: goto label_1cb000;
            case 0x1CB00Cu: goto label_1cb00c;
            case 0x1CB044u: goto label_1cb044;
            case 0x1CB048u: goto label_1cb048;
            case 0x1CB04Cu: goto label_1cb04c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CB074u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
