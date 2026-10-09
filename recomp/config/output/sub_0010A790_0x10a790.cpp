#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010A790
// Address: 0x10a790 - 0x10a830
void sub_0010A790_0x10a790(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010A790_0x10a790");
#endif

    switch (ctx->pc) {
        case 0x10a81cu: goto label_10a81c;
        default: break;
    }

    ctx->pc = 0x10a790u;

    // 0x10a790: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x10a790u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10a794: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x10a794u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x10a798: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x10a798u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10a79c: 0x804537c  j           func_114DF0
    ctx->pc = 0x10A79Cu;
    ctx->pc = 0x10A7A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10A79Cu;
            // 0x10a7a0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114DF0u;
    {
        auto targetFn = runtime->lookupFunction(0x114DF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x10A7A4u;
    // 0x10a7a4: 0x0  nop
    ctx->pc = 0x10a7a4u;
    // NOP
    // 0x10a7a8: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x10a7a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x10a7ac: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x10a7acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x10a7b0: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x10a7b0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a7b4: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x10a7b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a7b8: 0xafa40054  sw          $a0, 0x54($sp)
    ctx->pc = 0x10a7b8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 84), GPR_U32(ctx, 4));
    // 0x10a7bc: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x10a7bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a7c0: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x10a7c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x10a7c4: 0x240c0208  addiu       $t4, $zero, 0x208
    ctx->pc = 0x10a7c4u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 520));
    // 0x10a7c8: 0x27a60098  addiu       $a2, $sp, 0x98
    ctx->pc = 0x10a7c8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 152));
    // 0x10a7cc: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x10a7ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x10a7d0: 0xafa30010  sw          $v1, 0x10($sp)
    ctx->pc = 0x10a7d0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 3));
    // 0x10a7d4: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x10a7d4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x10a7d8: 0xffa70098  sd          $a3, 0x98($sp)
    ctx->pc = 0x10a7d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 7));
    // 0x10a7dc: 0xffa800a0  sd          $t0, 0xA0($sp)
    ctx->pc = 0x10a7dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 8));
    // 0x10a7e0: 0xffa900a8  sd          $t1, 0xA8($sp)
    ctx->pc = 0x10a7e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 9));
    // 0x10a7e4: 0xffaa00b0  sd          $t2, 0xB0($sp)
    ctx->pc = 0x10a7e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 10));
    // 0x10a7e8: 0xffab00b8  sd          $t3, 0xB8($sp)
    ctx->pc = 0x10a7e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 184), GPR_U64(ctx, 11));
    // 0x10a7ec: 0xe7ac0078  swc1        $f12, 0x78($sp)
    ctx->pc = 0x10a7ecu;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 120), bits); }
    // 0x10a7f0: 0xe7ad007c  swc1        $f13, 0x7C($sp)
    ctx->pc = 0x10a7f0u;
    { float f = ctx->f[13]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 124), bits); }
    // 0x10a7f4: 0xe7ae0080  swc1        $f14, 0x80($sp)
    ctx->pc = 0x10a7f4u;
    { float f = ctx->f[14]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 128), bits); }
    // 0x10a7f8: 0xe7af0084  swc1        $f15, 0x84($sp)
    ctx->pc = 0x10a7f8u;
    { float f = ctx->f[15]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 132), bits); }
    // 0x10a7fc: 0xe7b00088  swc1        $f16, 0x88($sp)
    ctx->pc = 0x10a7fcu;
    { float f = ctx->f[16]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 136), bits); }
    // 0x10a800: 0xe7b1008c  swc1        $f17, 0x8C($sp)
    ctx->pc = 0x10a800u;
    { float f = ctx->f[17]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 140), bits); }
    // 0x10a804: 0xe7b20090  swc1        $f18, 0x90($sp)
    ctx->pc = 0x10a804u;
    { float f = ctx->f[18]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 144), bits); }
    // 0x10a808: 0xe7b30094  swc1        $f19, 0x94($sp)
    ctx->pc = 0x10a808u;
    { float f = ctx->f[19]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 148), bits); }
    // 0x10a80c: 0xa7ac000c  sh          $t4, 0xC($sp)
    ctx->pc = 0x10a80cu;
    WRITE16(ADD32(GPR_U32(ctx, 29), 12), (uint16_t)GPR_U32(ctx, 12));
    // 0x10a810: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x10a810u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x10a814: 0xc04345a  jal         func_10D168
    ctx->pc = 0x10A814u;
    SET_GPR_U32(ctx, 31, 0x10A81Cu);
    ctx->pc = 0x10A818u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10A814u;
            // 0x10a818: 0xafa20008  sw          $v0, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D168u;
    if (runtime->hasFunction(0x10D168u)) {
        auto targetFn = runtime->lookupFunction(0x10D168u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A81Cu; }
        if (ctx->pc != 0x10A81Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D168_0x10d168(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A81Cu; }
        if (ctx->pc != 0x10A81Cu) { return; }
    }
    ctx->pc = 0x10A81Cu;
label_10a81c:
    // 0x10a81c: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x10a81cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10a820: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x10a820u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x10a824: 0xa0600000  sb          $zero, 0x0($v1)
    ctx->pc = 0x10a824u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x10a828: 0x3e00008  jr          $ra
    ctx->pc = 0x10A828u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10A82Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A828u;
            // 0x10a82c: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A81Cu: goto label_10a81c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10A830u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
