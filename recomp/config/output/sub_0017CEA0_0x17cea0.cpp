#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017CEA0
// Address: 0x17cea0 - 0x17d078
void sub_0017CEA0_0x17cea0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017CEA0_0x17cea0");
#endif

    switch (ctx->pc) {
        case 0x17cec4u: goto label_17cec4;
        case 0x17ced4u: goto label_17ced4;
        case 0x17cedcu: goto label_17cedc;
        case 0x17cf14u: goto label_17cf14;
        case 0x17cf1cu: goto label_17cf1c;
        case 0x17cf24u: goto label_17cf24;
        case 0x17cf2cu: goto label_17cf2c;
        case 0x17cf90u: goto label_17cf90;
        case 0x17cfacu: goto label_17cfac;
        case 0x17cfd0u: goto label_17cfd0;
        case 0x17cfe0u: goto label_17cfe0;
        case 0x17cfe8u: goto label_17cfe8;
        case 0x17d004u: goto label_17d004;
        case 0x17d02cu: goto label_17d02c;
        case 0x17d034u: goto label_17d034;
        default: break;
    }

    ctx->pc = 0x17cea0u;

    // 0x17cea0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17cea0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17cea4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x17cea4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cea8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17cea8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17ceac: 0x3c100023  lui         $s0, 0x23
    ctx->pc = 0x17ceacu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)35 << 16));
    // 0x17ceb0: 0x2610f2a0  addiu       $s0, $s0, -0xD60
    ctx->pc = 0x17ceb0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294963872));
    // 0x17ceb4: 0x240604a8  addiu       $a2, $zero, 0x4A8
    ctx->pc = 0x17ceb4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1192));
    // 0x17ceb8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x17ceb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x17cebc: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x17CEBCu;
    SET_GPR_U32(ctx, 31, 0x17CEC4u);
    ctx->pc = 0x17CEC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CEBCu;
            // 0x17cec0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CEC4u; }
        if (ctx->pc != 0x17CEC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CEC4u; }
        if (ctx->pc != 0x17CEC4u) { return; }
    }
    ctx->pc = 0x17CEC4u;
label_17cec4:
    // 0x17cec4: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x17cec4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x17cec8: 0x0  nop
    ctx->pc = 0x17cec8u;
    // NOP
    // 0x17cecc: 0xc05f482  jal         func_17D208
    ctx->pc = 0x17CECCu;
    SET_GPR_U32(ctx, 31, 0x17CED4u);
    ctx->pc = 0x17CED0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CECCu;
            // 0x17ced0: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D208u;
    if (runtime->hasFunction(0x17D208u)) {
        auto targetFn = runtime->lookupFunction(0x17D208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CED4u; }
        if (ctx->pc != 0x17CED4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D208_0x17d208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CED4u; }
        if (ctx->pc != 0x17CED4u) { return; }
    }
    ctx->pc = 0x17CED4u;
label_17ced4:
    // 0x17ced4: 0xc052472  jal         func_1491C8
    ctx->pc = 0x17CED4u;
    SET_GPR_U32(ctx, 31, 0x17CEDCu);
    ctx->pc = 0x1491C8u;
    if (runtime->hasFunction(0x1491C8u)) {
        auto targetFn = runtime->lookupFunction(0x1491C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CEDCu; }
        if (ctx->pc != 0x17CEDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001491C8_0x1491c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CEDCu; }
        if (ctx->pc != 0x17CEDCu) { return; }
    }
    ctx->pc = 0x17CEDCu;
label_17cedc:
    // 0x17cedc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17cedcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17cee0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x17cee0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17cee4: 0x8052498  j           func_149260
    ctx->pc = 0x17CEE4u;
    ctx->pc = 0x17CEE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CEE4u;
            // 0x17cee8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x149260u;
    {
        auto targetFn = runtime->lookupFunction(0x149260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x17CEECu;
    // 0x17ceec: 0x0  nop
    ctx->pc = 0x17ceecu;
    // NOP
    // 0x17cef0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17cef0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17cef4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x17cef4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x17cef8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17cef8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17cefc: 0x2450f298  addiu       $s0, $v0, -0xD68
    ctx->pc = 0x17cefcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963864));
    // 0x17cf00: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x17cf00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17cf04: 0x1860000c  blez        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x17CF04u;
    {
        const bool branch_taken_0x17cf04 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x17CF08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CF04u;
            // 0x17cf08: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cf04) {
            ctx->pc = 0x17CF38u;
            goto label_17cf38;
        }
    }
    ctx->pc = 0x17CF0Cu;
    // 0x17cf0c: 0xc05f5d0  jal         func_17D740
    ctx->pc = 0x17CF0Cu;
    SET_GPR_U32(ctx, 31, 0x17CF14u);
    ctx->pc = 0x17D740u;
    if (runtime->hasFunction(0x17D740u)) {
        auto targetFn = runtime->lookupFunction(0x17D740u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CF14u; }
        if (ctx->pc != 0x17CF14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D740_0x17d740(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CF14u; }
        if (ctx->pc != 0x17CF14u) { return; }
    }
    ctx->pc = 0x17CF14u;
label_17cf14:
    // 0x17cf14: 0xc05e99e  jal         func_17A678
    ctx->pc = 0x17CF14u;
    SET_GPR_U32(ctx, 31, 0x17CF1Cu);
    ctx->pc = 0x17A678u;
    if (runtime->hasFunction(0x17A678u)) {
        auto targetFn = runtime->lookupFunction(0x17A678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CF1Cu; }
        if (ctx->pc != 0x17CF1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A678_0x17a678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CF1Cu; }
        if (ctx->pc != 0x17CF1Cu) { return; }
    }
    ctx->pc = 0x17CF1Cu;
label_17cf1c:
    // 0x17cf1c: 0xc05f594  jal         func_17D650
    ctx->pc = 0x17CF1Cu;
    SET_GPR_U32(ctx, 31, 0x17CF24u);
    ctx->pc = 0x17D650u;
    if (runtime->hasFunction(0x17D650u)) {
        auto targetFn = runtime->lookupFunction(0x17D650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CF24u; }
        if (ctx->pc != 0x17CF24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D650_0x17d650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CF24u; }
        if (ctx->pc != 0x17CF24u) { return; }
    }
    ctx->pc = 0x17CF24u;
label_17cf24:
    // 0x17cf24: 0xc052480  jal         func_149200
    ctx->pc = 0x17CF24u;
    SET_GPR_U32(ctx, 31, 0x17CF2Cu);
    ctx->pc = 0x149200u;
    if (runtime->hasFunction(0x149200u)) {
        auto targetFn = runtime->lookupFunction(0x149200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CF2Cu; }
        if (ctx->pc != 0x17CF2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00149200_0x149200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CF2Cu; }
        if (ctx->pc != 0x17CF2Cu) { return; }
    }
    ctx->pc = 0x17CF2Cu;
label_17cf2c:
    // 0x17cf2c: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x17cf2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17cf30: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x17cf30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x17cf34: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x17cf34u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
label_17cf38:
    // 0x17cf38: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17cf38u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17cf3c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x17cf3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17cf40: 0x3e00008  jr          $ra
    ctx->pc = 0x17CF40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17CF44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CF40u;
            // 0x17cf44: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17CEC4u: goto label_17cec4;
            case 0x17CED4u: goto label_17ced4;
            case 0x17CEDCu: goto label_17cedc;
            case 0x17CF14u: goto label_17cf14;
            case 0x17CF1Cu: goto label_17cf1c;
            case 0x17CF24u: goto label_17cf24;
            case 0x17CF2Cu: goto label_17cf2c;
            case 0x17CF38u: goto label_17cf38;
            case 0x17CF90u: goto label_17cf90;
            case 0x17CFACu: goto label_17cfac;
            case 0x17CFD0u: goto label_17cfd0;
            case 0x17CFD8u: goto label_17cfd8;
            case 0x17CFE0u: goto label_17cfe0;
            case 0x17CFE8u: goto label_17cfe8;
            case 0x17D004u: goto label_17d004;
            case 0x17D024u: goto label_17d024;
            case 0x17D02Cu: goto label_17d02c;
            case 0x17D034u: goto label_17d034;
            case 0x17D040u: goto label_17d040;
            case 0x17D054u: goto label_17d054;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17CF48u;
    // 0x17cf48: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x17cf48u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x17cf4c: 0x2442f2a8  addiu       $v0, $v0, -0xD58
    ctx->pc = 0x17cf4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963880));
    // 0x17cf50: 0xac450004  sw          $a1, 0x4($v0)
    ctx->pc = 0x17cf50u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 5));
    // 0x17cf54: 0x3e00008  jr          $ra
    ctx->pc = 0x17CF54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17CF58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CF54u;
            // 0x17cf58: 0xac440000  sw          $a0, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17CEC4u: goto label_17cec4;
            case 0x17CED4u: goto label_17ced4;
            case 0x17CEDCu: goto label_17cedc;
            case 0x17CF14u: goto label_17cf14;
            case 0x17CF1Cu: goto label_17cf1c;
            case 0x17CF24u: goto label_17cf24;
            case 0x17CF2Cu: goto label_17cf2c;
            case 0x17CF38u: goto label_17cf38;
            case 0x17CF90u: goto label_17cf90;
            case 0x17CFACu: goto label_17cfac;
            case 0x17CFD0u: goto label_17cfd0;
            case 0x17CFD8u: goto label_17cfd8;
            case 0x17CFE0u: goto label_17cfe0;
            case 0x17CFE8u: goto label_17cfe8;
            case 0x17D004u: goto label_17d004;
            case 0x17D024u: goto label_17d024;
            case 0x17D02Cu: goto label_17d02c;
            case 0x17D034u: goto label_17d034;
            case 0x17D040u: goto label_17d040;
            case 0x17D054u: goto label_17d054;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17CF5Cu;
    // 0x17cf5c: 0x0  nop
    ctx->pc = 0x17cf5cu;
    // NOP
    // 0x17cf60: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17cf60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17cf64: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17cf64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17cf68: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x17cf68u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cf6c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17cf6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17cf70: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x17cf70u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cf74: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17cf74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17cf78: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x17cf78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x17cf7c: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x17cf7cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cf80: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x17cf80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x17cf84: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x17cf84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x17cf88: 0xc05f41e  jal         func_17D078
    ctx->pc = 0x17CF88u;
    SET_GPR_U32(ctx, 31, 0x17CF90u);
    ctx->pc = 0x17CF8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CF88u;
            // 0x17cf8c: 0x80a02d  daddu       $s4, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D078u;
    if (runtime->hasFunction(0x17D078u)) {
        auto targetFn = runtime->lookupFunction(0x17D078u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CF90u; }
        if (ctx->pc != 0x17CF90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D078_0x17d078(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CF90u; }
        if (ctx->pc != 0x17CF90u) { return; }
    }
    ctx->pc = 0x17CF90u;
label_17cf90:
    // 0x17cf90: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x17cf90u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cf94: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x17cf94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cf98: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17cf98u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cf9c: 0x1240002d  beqz        $s2, . + 4 + (0x2D << 2)
    ctx->pc = 0x17CF9Cu;
    {
        const bool branch_taken_0x17cf9c = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x17CFA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CF9Cu;
            // 0x17cfa0: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cf9c) {
            ctx->pc = 0x17D054u;
            goto label_17d054;
        }
    }
    ctx->pc = 0x17CFA4u;
    // 0x17cfa4: 0xc05f45a  jal         func_17D168
    ctx->pc = 0x17CFA4u;
    SET_GPR_U32(ctx, 31, 0x17CFACu);
    ctx->pc = 0x17D168u;
    if (runtime->hasFunction(0x17D168u)) {
        auto targetFn = runtime->lookupFunction(0x17D168u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CFACu; }
        if (ctx->pc != 0x17CFACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D168_0x17d168(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CFACu; }
        if (ctx->pc != 0x17CFACu) { return; }
    }
    ctx->pc = 0x17CFACu;
label_17cfac:
    // 0x17cfac: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17cfacu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17cfb0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x17cfb0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cfb4: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x17cfb4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cfb8: 0x10430007  beq         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x17CFB8u;
    {
        const bool branch_taken_0x17cfb8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x17CFBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CFB8u;
            // 0x17cfbc: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cfb8) {
            ctx->pc = 0x17CFD8u;
            goto label_17cfd8;
        }
    }
    ctx->pc = 0x17CFC0u;
    // 0x17cfc0: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17cfc0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x17cfc4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x17cfc4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cfc8: 0xc05f472  jal         func_17D1C8
    ctx->pc = 0x17CFC8u;
    SET_GPR_U32(ctx, 31, 0x17CFD0u);
    ctx->pc = 0x17CFCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CFC8u;
            // 0x17cfcc: 0x24c613c8  addiu       $a2, $a2, 0x13C8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 5064));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D1C8u;
    if (runtime->hasFunction(0x17D1C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D1C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CFD0u; }
        if (ctx->pc != 0x17CFD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CFD0u; }
        if (ctx->pc != 0x17CFD0u) { return; }
    }
    ctx->pc = 0x17CFD0u;
label_17cfd0:
    // 0x17cfd0: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x17CFD0u;
    {
        const bool branch_taken_0x17cfd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17CFD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CFD0u;
            // 0x17cfd4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cfd0) {
            ctx->pc = 0x17D054u;
            goto label_17d054;
        }
    }
    ctx->pc = 0x17CFD8u;
label_17cfd8:
    // 0x17cfd8: 0xc05f432  jal         func_17D0C8
    ctx->pc = 0x17CFD8u;
    SET_GPR_U32(ctx, 31, 0x17CFE0u);
    ctx->pc = 0x17CFDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CFD8u;
            // 0x17cfdc: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D0C8u;
    if (runtime->hasFunction(0x17D0C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D0C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CFE0u; }
        if (ctx->pc != 0x17CFE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D0C8_0x17d0c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CFE0u; }
        if (ctx->pc != 0x17CFE0u) { return; }
    }
    ctx->pc = 0x17CFE0u;
label_17cfe0:
    // 0x17cfe0: 0xc05f5d2  jal         func_17D748
    ctx->pc = 0x17CFE0u;
    SET_GPR_U32(ctx, 31, 0x17CFE8u);
    ctx->pc = 0x17D748u;
    if (runtime->hasFunction(0x17D748u)) {
        auto targetFn = runtime->lookupFunction(0x17D748u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CFE8u; }
        if (ctx->pc != 0x17CFE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D748_0x17d748(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CFE8u; }
        if (ctx->pc != 0x17CFE8u) { return; }
    }
    ctx->pc = 0x17CFE8u;
label_17cfe8:
    // 0x17cfe8: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17cfe8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x17cfec: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x17cfecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cff0: 0x24c613f8  addiu       $a2, $a2, 0x13F8
    ctx->pc = 0x17cff0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 5112));
    // 0x17cff4: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x17CFF4u;
    {
        const bool branch_taken_0x17cff4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17CFF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CFF4u;
            // 0x17cff8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cff4) {
            ctx->pc = 0x17D024u;
            goto label_17d024;
        }
    }
    ctx->pc = 0x17CFFCu;
    // 0x17cffc: 0xc05e9a0  jal         func_17A680
    ctx->pc = 0x17CFFCu;
    SET_GPR_U32(ctx, 31, 0x17D004u);
    ctx->pc = 0x17D000u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CFFCu;
            // 0x17d000: 0xae420024  sw          $v0, 0x24($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17A680u;
    if (runtime->hasFunction(0x17A680u)) {
        auto targetFn = runtime->lookupFunction(0x17A680u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D004u; }
        if (ctx->pc != 0x17D004u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A680_0x17a680(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D004u; }
        if (ctx->pc != 0x17D004u) { return; }
    }
    ctx->pc = 0x17D004u;
label_17d004:
    // 0x17d004: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17d004u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x17d008: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x17d008u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d00c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x17d00cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x17d010: 0x2448f2a0  addiu       $t0, $v0, -0xD60
    ctx->pc = 0x17d010u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963872));
    // 0x17d014: 0x24c61418  addiu       $a2, $a2, 0x1418
    ctx->pc = 0x17d014u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 5144));
    // 0x17d018: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x17d018u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d01c: 0x14e00008  bnez        $a3, . + 4 + (0x8 << 2)
    ctx->pc = 0x17D01Cu;
    {
        const bool branch_taken_0x17d01c = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x17D020u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D01Cu;
            // 0x17d020: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17d01c) {
            ctx->pc = 0x17D040u;
            goto label_17d040;
        }
    }
    ctx->pc = 0x17D024u;
label_17d024:
    // 0x17d024: 0xc05f472  jal         func_17D1C8
    ctx->pc = 0x17D024u;
    SET_GPR_U32(ctx, 31, 0x17D02Cu);
    ctx->pc = 0x17D1C8u;
    if (runtime->hasFunction(0x17D1C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D1C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D02Cu; }
        if (ctx->pc != 0x17D02Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D02Cu; }
        if (ctx->pc != 0x17D02Cu) { return; }
    }
    ctx->pc = 0x17D02Cu;
label_17d02c:
    // 0x17d02c: 0xc05f45e  jal         func_17D178
    ctx->pc = 0x17D02Cu;
    SET_GPR_U32(ctx, 31, 0x17D034u);
    ctx->pc = 0x17D030u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D02Cu;
            // 0x17d030: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D178u;
    if (runtime->hasFunction(0x17D178u)) {
        auto targetFn = runtime->lookupFunction(0x17D178u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D034u; }
        if (ctx->pc != 0x17D034u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D178_0x17d178(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D034u; }
        if (ctx->pc != 0x17D034u) { return; }
    }
    ctx->pc = 0x17D034u;
label_17d034:
    // 0x17d034: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x17D034u;
    {
        const bool branch_taken_0x17d034 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17D038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D034u;
            // 0x17d038: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17d034) {
            ctx->pc = 0x17D054u;
            goto label_17d054;
        }
    }
    ctx->pc = 0x17D03Cu;
    // 0x17d03c: 0x0  nop
    ctx->pc = 0x17d03cu;
    // NOP
label_17d040:
    // 0x17d040: 0x8d030000  lw          $v1, 0x0($t0)
    ctx->pc = 0x17d040u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x17d044: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x17d044u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d048: 0xae470030  sw          $a3, 0x30($s2)
    ctx->pc = 0x17d048u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 48), GPR_U32(ctx, 7));
    // 0x17d04c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x17d04cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x17d050: 0xad030000  sw          $v1, 0x0($t0)
    ctx->pc = 0x17d050u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 3));
label_17d054:
    // 0x17d054: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17d054u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d058: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17d058u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17d05c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17d05cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17d060: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x17d060u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17d064: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x17d064u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17d068: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x17d068u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x17d06c: 0x3e00008  jr          $ra
    ctx->pc = 0x17D06Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D070u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D06Cu;
            // 0x17d070: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17CEC4u: goto label_17cec4;
            case 0x17CED4u: goto label_17ced4;
            case 0x17CEDCu: goto label_17cedc;
            case 0x17CF14u: goto label_17cf14;
            case 0x17CF1Cu: goto label_17cf1c;
            case 0x17CF24u: goto label_17cf24;
            case 0x17CF2Cu: goto label_17cf2c;
            case 0x17CF38u: goto label_17cf38;
            case 0x17CF90u: goto label_17cf90;
            case 0x17CFACu: goto label_17cfac;
            case 0x17CFD0u: goto label_17cfd0;
            case 0x17CFD8u: goto label_17cfd8;
            case 0x17CFE0u: goto label_17cfe0;
            case 0x17CFE8u: goto label_17cfe8;
            case 0x17D004u: goto label_17d004;
            case 0x17D024u: goto label_17d024;
            case 0x17D02Cu: goto label_17d02c;
            case 0x17D034u: goto label_17d034;
            case 0x17D040u: goto label_17d040;
            case 0x17D054u: goto label_17d054;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D074u;
    // 0x17d074: 0x0  nop
    ctx->pc = 0x17d074u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
