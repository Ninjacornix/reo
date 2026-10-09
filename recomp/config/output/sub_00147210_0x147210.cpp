#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00147210
// Address: 0x147210 - 0x147298
void sub_00147210_0x147210(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00147210_0x147210");
#endif

    switch (ctx->pc) {
        case 0x14722cu: goto label_14722c;
        default: break;
    }

    ctx->pc = 0x147210u;

    // 0x147210: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x147210u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x147214: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x147214u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x147218: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x147218u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x14721c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x14721cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147220: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x147220u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x147224: 0xc047598  jal         func_11D660
    ctx->pc = 0x147224u;
    SET_GPR_U32(ctx, 31, 0x14722Cu);
    ctx->pc = 0x147228u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x147224u;
            // 0x147228: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14722Cu; }
        if (ctx->pc != 0x14722Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14722Cu; }
        if (ctx->pc != 0x14722Cu) { return; }
    }
    ctx->pc = 0x14722Cu;
label_14722c:
    // 0x14722c: 0x3c030fff  lui         $v1, 0xFFF
    ctx->pc = 0x14722cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4095 << 16));
    // 0x147230: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x147230u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x147234: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x147234u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x147238: 0x3c068000  lui         $a2, 0x8000
    ctx->pc = 0x147238u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32768 << 16));
    // 0x14723c: 0x2038024  and         $s0, $s0, $v1
    ctx->pc = 0x14723cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & GPR_U64(ctx, 3));
    // 0x147240: 0x34a5b010  ori         $a1, $a1, 0xB010
    ctx->pc = 0x147240u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)45072);
    // 0x147244: 0x2068025  or          $s0, $s0, $a2
    ctx->pc = 0x147244u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 6));
    // 0x147248: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x147248u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x14724c: 0xacb00000  sw          $s0, 0x0($a1)
    ctx->pc = 0x14724cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 16));
    // 0x147250: 0x3484b020  ori         $a0, $a0, 0xB020
    ctx->pc = 0x147250u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)45088);
    // 0x147254: 0x118903  sra         $s1, $s1, 4
    ctx->pc = 0x147254u;
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 17), 4));
    // 0x147258: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x147258u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x14725c: 0xac910000  sw          $s1, 0x0($a0)
    ctx->pc = 0x14725cu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 17)); // MMIO: 0x10000000
    // 0x147260: 0x3463b000  ori         $v1, $v1, 0xB000
    ctx->pc = 0x147260u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)45056);
    // 0x147264: 0x24040100  addiu       $a0, $zero, 0x100
    ctx->pc = 0x147264u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x147268: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x147268u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x14726c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x14726Cu;
    {
        const bool branch_taken_0x14726c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x147270u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14726Cu;
            // 0x147270: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14726c) {
            ctx->pc = 0x147284u;
            goto label_147284;
        }
    }
    ctx->pc = 0x147274u;
    // 0x147274: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x147274u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x147278: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x147278u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x14727c: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x14727Cu;
    ctx->pc = 0x147280u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14727Cu;
            // 0x147280: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x147284u;
label_147284:
    // 0x147284: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x147284u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x147288: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x147288u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x14728c: 0x3e00008  jr          $ra
    ctx->pc = 0x14728Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14728Cu;
            // 0x147290: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x14722Cu: goto label_14722c;
            case 0x147284u: goto label_147284;
            default: break;
        }
        return;
    }
    ctx->pc = 0x147294u;
    // 0x147294: 0x0  nop
    ctx->pc = 0x147294u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
