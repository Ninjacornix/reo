#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F6210
// Address: 0x1f6210 - 0x1f6350
void sub_001F6210_0x1f6210(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F6210_0x1f6210");
#endif

    switch (ctx->pc) {
        case 0x1f6234u: goto label_1f6234;
        case 0x1f6264u: goto label_1f6264;
        case 0x1f62b0u: goto label_1f62b0;
        case 0x1f62c8u: goto label_1f62c8;
        case 0x1f62d8u: goto label_1f62d8;
        case 0x1f6324u: goto label_1f6324;
        case 0x1f633cu: goto label_1f633c;
        default: break;
    }

    ctx->pc = 0x1f6210u;

    // 0x1f6210: 0x27bdfbe0  addiu       $sp, $sp, -0x420
    ctx->pc = 0x1f6210u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966240));
    // 0x1f6214: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f6214u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f6218: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f6218u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f621c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f621cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f6220: 0x8c22eaf0  lw          $v0, -0x1510($at)
    ctx->pc = 0x1f6220u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961904)));
    // 0x1f6224: 0x10400045  beqz        $v0, . + 4 + (0x45 << 2)
    ctx->pc = 0x1F6224u;
    {
        const bool branch_taken_0x1f6224 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6228u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6224u;
            // 0x1f6228: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6224) {
            ctx->pc = 0x1F633Cu;
            goto label_1f633c;
        }
    }
    ctx->pc = 0x1F622Cu;
    // 0x1f622c: 0xc07d20c  jal         func_1F4830
    ctx->pc = 0x1F622Cu;
    SET_GPR_U32(ctx, 31, 0x1F6234u);
    ctx->pc = 0x1F4830u;
    if (runtime->hasFunction(0x1F4830u)) {
        auto targetFn = runtime->lookupFunction(0x1F4830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6234u; }
        if (ctx->pc != 0x1F6234u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4830_0x1f4830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6234u; }
        if (ctx->pc != 0x1F6234u) { return; }
    }
    ctx->pc = 0x1F6234u;
label_1f6234:
    // 0x1f6234: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1f6234u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1f6238: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F6238u;
    {
        const bool branch_taken_0x1f6238 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F623Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6238u;
            // 0x1f623c: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6238) {
            ctx->pc = 0x1F6248u;
            goto label_1f6248;
        }
    }
    ctx->pc = 0x1F6240u;
    // 0x1f6240: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1F6240u;
    {
        const bool branch_taken_0x1f6240 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6244u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6240u;
            // 0x1f6244: 0xac22c7f8  sw          $v0, -0x3808($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294952952), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6240) {
            ctx->pc = 0x1F6254u;
            goto label_1f6254;
        }
    }
    ctx->pc = 0x1F6248u;
label_1f6248:
    // 0x1f6248: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1f6248u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1f624c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1f624cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1f6250: 0xac22c7f8  sw          $v0, -0x3808($at)
    ctx->pc = 0x1f6250u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294952952), GPR_U32(ctx, 2));
label_1f6254:
    // 0x1f6254: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1f6254u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6258: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x1f6258u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f625c: 0xc07d244  jal         func_1F4910
    ctx->pc = 0x1F625Cu;
    SET_GPR_U32(ctx, 31, 0x1F6264u);
    ctx->pc = 0x1F6260u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F625Cu;
            // 0x1f6260: 0x240600ff  addiu       $a2, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4910u;
    if (runtime->hasFunction(0x1F4910u)) {
        auto targetFn = runtime->lookupFunction(0x1F4910u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6264u; }
        if (ctx->pc != 0x1F6264u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4910_0x1f4910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6264u; }
        if (ctx->pc != 0x1F6264u) { return; }
    }
    ctx->pc = 0x1F6264u;
label_1f6264:
    // 0x1f6264: 0x441000b  bgez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1F6264u;
    {
        const bool branch_taken_0x1f6264 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1F6268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6264u;
            // 0x1f6268: 0x2404ffff  addiu       $a0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6264) {
            ctx->pc = 0x1F6294u;
            goto label_1f6294;
        }
    }
    ctx->pc = 0x1F626Cu;
    // 0x1f626c: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x1f626cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6270: 0xae04008c  sw          $a0, 0x8C($s0)
    ctx->pc = 0x1f6270u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 4));
    // 0x1f6274: 0xa2030000  sb          $v1, 0x0($s0)
    ctx->pc = 0x1f6274u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f6278: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1f6278u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f627c: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f627cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6280: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x1f6280u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6284: 0xa6000004  sh          $zero, 0x4($s0)
    ctx->pc = 0x1f6284u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6288: 0xa6000006  sh          $zero, 0x6($s0)
    ctx->pc = 0x1f6288u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f628c: 0xa6000008  sh          $zero, 0x8($s0)
    ctx->pc = 0x1f628cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6290: 0xa600000a  sh          $zero, 0xA($s0)
    ctx->pc = 0x1f6290u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 0));
label_1f6294:
    // 0x1f6294: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1F6294u;
    {
        const bool branch_taken_0x1f6294 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6294u;
            // 0x1f6298: 0x3c040034  lui         $a0, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6294) {
            ctx->pc = 0x1F62B8u;
            goto label_1f62b8;
        }
    }
    ctx->pc = 0x1F629Cu;
    // 0x1f629c: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1f629cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1f62a0: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x1f62a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f62a4: 0x2484c6f0  addiu       $a0, $a0, -0x3910
    ctx->pc = 0x1f62a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952688));
    // 0x1f62a8: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1F62A8u;
    SET_GPR_U32(ctx, 31, 0x1F62B0u);
    ctx->pc = 0x1F62ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F62A8u;
            // 0x1f62ac: 0x24060100  addiu       $a2, $zero, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F62B0u; }
        if (ctx->pc != 0x1F62B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F62B0u; }
        if (ctx->pc != 0x1F62B0u) { return; }
    }
    ctx->pc = 0x1F62B0u;
label_1f62b0:
    // 0x1f62b0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1F62B0u;
    {
        const bool branch_taken_0x1f62b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F62B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F62B0u;
            // 0x1f62b4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f62b0) {
            ctx->pc = 0x1F62CCu;
            goto label_1f62cc;
        }
    }
    ctx->pc = 0x1F62B8u;
label_1f62b8:
    // 0x1f62b8: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x1f62b8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x1f62bc: 0x2484c6f0  addiu       $a0, $a0, -0x3910
    ctx->pc = 0x1f62bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952688));
    // 0x1f62c0: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1F62C0u;
    SET_GPR_U32(ctx, 31, 0x1F62C8u);
    ctx->pc = 0x1F62C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F62C0u;
            // 0x1f62c4: 0x24a59b40  addiu       $a1, $a1, -0x64C0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941504));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F62C8u; }
        if (ctx->pc != 0x1F62C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F62C8u; }
        if (ctx->pc != 0x1F62C8u) { return; }
    }
    ctx->pc = 0x1F62C8u;
label_1f62c8:
    // 0x1f62c8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1f62c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1f62cc:
    // 0x1f62cc: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x1f62ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f62d0: 0xc07d244  jal         func_1F4910
    ctx->pc = 0x1F62D0u;
    SET_GPR_U32(ctx, 31, 0x1F62D8u);
    ctx->pc = 0x1F62D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F62D0u;
            // 0x1f62d4: 0x240600ff  addiu       $a2, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4910u;
    if (runtime->hasFunction(0x1F4910u)) {
        auto targetFn = runtime->lookupFunction(0x1F4910u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F62D8u; }
        if (ctx->pc != 0x1F62D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4910_0x1f4910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F62D8u; }
        if (ctx->pc != 0x1F62D8u) { return; }
    }
    ctx->pc = 0x1F62D8u;
label_1f62d8:
    // 0x1f62d8: 0x441000b  bgez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1F62D8u;
    {
        const bool branch_taken_0x1f62d8 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1F62DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F62D8u;
            // 0x1f62dc: 0x2404ffff  addiu       $a0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f62d8) {
            ctx->pc = 0x1F6308u;
            goto label_1f6308;
        }
    }
    ctx->pc = 0x1F62E0u;
    // 0x1f62e0: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x1f62e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f62e4: 0xae04008c  sw          $a0, 0x8C($s0)
    ctx->pc = 0x1f62e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 4));
    // 0x1f62e8: 0xa2030000  sb          $v1, 0x0($s0)
    ctx->pc = 0x1f62e8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f62ec: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1f62ecu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f62f0: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f62f0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f62f4: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x1f62f4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f62f8: 0xa6000004  sh          $zero, 0x4($s0)
    ctx->pc = 0x1f62f8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f62fc: 0xa6000006  sh          $zero, 0x6($s0)
    ctx->pc = 0x1f62fcu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6300: 0xa6000008  sh          $zero, 0x8($s0)
    ctx->pc = 0x1f6300u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6304: 0xa600000a  sh          $zero, 0xA($s0)
    ctx->pc = 0x1f6304u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 0));
label_1f6308:
    // 0x1f6308: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1F6308u;
    {
        const bool branch_taken_0x1f6308 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F630Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6308u;
            // 0x1f630c: 0x3c040034  lui         $a0, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6308) {
            ctx->pc = 0x1F632Cu;
            goto label_1f632c;
        }
    }
    ctx->pc = 0x1F6310u;
    // 0x1f6310: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1f6310u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1f6314: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x1f6314u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f6318: 0x2484cc60  addiu       $a0, $a0, -0x33A0
    ctx->pc = 0x1f6318u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954080));
    // 0x1f631c: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1F631Cu;
    SET_GPR_U32(ctx, 31, 0x1F6324u);
    ctx->pc = 0x1F6320u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F631Cu;
            // 0x1f6320: 0x24060100  addiu       $a2, $zero, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6324u; }
        if (ctx->pc != 0x1F6324u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6324u; }
        if (ctx->pc != 0x1F6324u) { return; }
    }
    ctx->pc = 0x1F6324u;
label_1f6324:
    // 0x1f6324: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1F6324u;
    {
        const bool branch_taken_0x1f6324 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6324u;
            // 0x1f6328: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6324) {
            ctx->pc = 0x1F6340u;
            goto label_1f6340;
        }
    }
    ctx->pc = 0x1F632Cu;
label_1f632c:
    // 0x1f632c: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x1f632cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x1f6330: 0x2484cc60  addiu       $a0, $a0, -0x33A0
    ctx->pc = 0x1f6330u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954080));
    // 0x1f6334: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1F6334u;
    SET_GPR_U32(ctx, 31, 0x1F633Cu);
    ctx->pc = 0x1F6338u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6334u;
            // 0x1f6338: 0x24a59b80  addiu       $a1, $a1, -0x6480 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941568));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F633Cu; }
        if (ctx->pc != 0x1F633Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F633Cu; }
        if (ctx->pc != 0x1F633Cu) { return; }
    }
    ctx->pc = 0x1F633Cu;
label_1f633c:
    // 0x1f633c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f633cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1f6340:
    // 0x1f6340: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f6340u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6344: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f6344u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f6348: 0x3e00008  jr          $ra
    ctx->pc = 0x1F6348u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F634Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6348u;
            // 0x1f634c: 0x27bd0420  addiu       $sp, $sp, 0x420 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 1056));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F6234u: goto label_1f6234;
            case 0x1F6248u: goto label_1f6248;
            case 0x1F6254u: goto label_1f6254;
            case 0x1F6264u: goto label_1f6264;
            case 0x1F6294u: goto label_1f6294;
            case 0x1F62B0u: goto label_1f62b0;
            case 0x1F62B8u: goto label_1f62b8;
            case 0x1F62C8u: goto label_1f62c8;
            case 0x1F62CCu: goto label_1f62cc;
            case 0x1F62D8u: goto label_1f62d8;
            case 0x1F6308u: goto label_1f6308;
            case 0x1F6324u: goto label_1f6324;
            case 0x1F632Cu: goto label_1f632c;
            case 0x1F633Cu: goto label_1f633c;
            case 0x1F6340u: goto label_1f6340;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F6350u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
