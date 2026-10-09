#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016A1C0
// Address: 0x16a1c0 - 0x16a290
void sub_0016A1C0_0x16a1c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016A1C0_0x16a1c0");
#endif

    switch (ctx->pc) {
        case 0x16a1f8u: goto label_16a1f8;
        case 0x16a200u: goto label_16a200;
        case 0x16a238u: goto label_16a238;
        case 0x16a258u: goto label_16a258;
        default: break;
    }

    ctx->pc = 0x16a1c0u;

    // 0x16a1c0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x16a1c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x16a1c4: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x16a1c4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a1c8: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x16a1c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x16a1cc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16a1ccu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a1d0: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x16a1d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x16a1d4: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x16a1d4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a1d8: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x16a1d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x16a1dc: 0x3c127fff  lui         $s2, 0x7FFF
    ctx->pc = 0x16a1dcu;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)32767 << 16));
    // 0x16a1e0: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x16a1e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x16a1e4: 0x3652fffe  ori         $s2, $s2, 0xFFFE
    ctx->pc = 0x16a1e4u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | (uint64_t)(uint16_t)65534);
    // 0x16a1e8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x16a1e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x16a1ec: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x16A1ECu;
    {
        const bool branch_taken_0x16a1ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A1F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A1ECu;
            // 0x16a1f0: 0x8e130028  lw          $s3, 0x28($s0) (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a1ec) {
            ctx->pc = 0x16A214u;
            goto label_16a214;
        }
    }
    ctx->pc = 0x16A1F4u;
    // 0x16a1f4: 0x0  nop
    ctx->pc = 0x16a1f4u;
    // NOP
label_16a1f8:
    // 0x16a1f8: 0xc05a8be  jal         func_16A2F8
    ctx->pc = 0x16A1F8u;
    SET_GPR_U32(ctx, 31, 0x16A200u);
    ctx->pc = 0x16A2F8u;
    if (runtime->hasFunction(0x16A2F8u)) {
        auto targetFn = runtime->lookupFunction(0x16A2F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A200u; }
        if (ctx->pc != 0x16A200u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016A2F8_0x16a2f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A200u; }
        if (ctx->pc != 0x16A200u) { return; }
    }
    ctx->pc = 0x16A200u;
label_16a200:
    // 0x16a200: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x16a200u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a204: 0x5460001b  bnel        $v1, $zero, . + 4 + (0x1B << 2)
    ctx->pc = 0x16A204u;
    {
        const bool branch_taken_0x16a204 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x16a204) {
            ctx->pc = 0x16A208u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A204u;
            // 0x16a208: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A274u;
            goto label_16a274;
        }
    }
    ctx->pc = 0x16A20Cu;
    // 0x16a20c: 0x8fa2000c  lw          $v0, 0xC($sp)
    ctx->pc = 0x16a20cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x16a210: 0x2228821  addu        $s1, $s1, $v0
    ctx->pc = 0x16a210u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
label_16a214:
    // 0x16a214: 0x251102a  slt         $v0, $s2, $s1
    ctx->pc = 0x16a214u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x16a218: 0x54400016  bnel        $v0, $zero, . + 4 + (0x16 << 2)
    ctx->pc = 0x16A218u;
    {
        const bool branch_taken_0x16a218 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16a218) {
            ctx->pc = 0x16A21Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A218u;
            // 0x16a21c: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A274u;
            goto label_16a274;
        }
    }
    ctx->pc = 0x16A220u;
    // 0x16a220: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16a220u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a224: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x16a224u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a228: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x16a228u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a22c: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x16a22cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x16a230: 0xc05a8a4  jal         func_16A290
    ctx->pc = 0x16A230u;
    SET_GPR_U32(ctx, 31, 0x16A238u);
    ctx->pc = 0x16A234u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A230u;
            // 0x16a234: 0x27a80008  addiu       $t0, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16A290u;
    if (runtime->hasFunction(0x16A290u)) {
        auto targetFn = runtime->lookupFunction(0x16A290u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A238u; }
        if (ctx->pc != 0x16A238u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016A290_0x16a290(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A238u; }
        if (ctx->pc != 0x16A238u) { return; }
    }
    ctx->pc = 0x16A238u;
label_16a238:
    // 0x16a238: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16a238u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a23c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x16a23cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a240: 0x1460000b  bnez        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x16A240u;
    {
        const bool branch_taken_0x16a240 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x16A244u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A240u;
            // 0x16a244: 0x27a7000c  addiu       $a3, $sp, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a240) {
            ctx->pc = 0x16A270u;
            goto label_16a270;
        }
    }
    ctx->pc = 0x16A248u;
    // 0x16a248: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x16a248u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16a24c: 0x8fa60004  lw          $a2, 0x4($sp)
    ctx->pc = 0x16a24cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x16a250: 0xc05a8c6  jal         func_16A318
    ctx->pc = 0x16A250u;
    SET_GPR_U32(ctx, 31, 0x16A258u);
    ctx->pc = 0x16A254u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A250u;
            // 0x16a254: 0x8fa80008  lw          $t0, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16A318u;
    if (runtime->hasFunction(0x16A318u)) {
        auto targetFn = runtime->lookupFunction(0x16A318u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A258u; }
        if (ctx->pc != 0x16A258u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016A318_0x16a318(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A258u; }
        if (ctx->pc != 0x16A258u) { return; }
    }
    ctx->pc = 0x16A258u;
label_16a258:
    // 0x16a258: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x16a258u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a25c: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x16A25Cu;
    {
        const bool branch_taken_0x16a25c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x16A260u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A25Cu;
            // 0x16a260: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a25c) {
            ctx->pc = 0x16A270u;
            goto label_16a270;
        }
    }
    ctx->pc = 0x16A264u;
    // 0x16a264: 0x8fa5000c  lw          $a1, 0xC($sp)
    ctx->pc = 0x16a264u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x16a268: 0x14a0ffe3  bnez        $a1, . + 4 + (-0x1D << 2)
    ctx->pc = 0x16A268u;
    {
        const bool branch_taken_0x16a268 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x16a268) {
            ctx->pc = 0x16A1F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16a1f8;
        }
    }
    ctx->pc = 0x16A270u;
label_16a270:
    // 0x16a270: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x16a270u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_16a274:
    // 0x16a274: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x16a274u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a278: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x16a278u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16a27c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x16a27cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16a280: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x16a280u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16a284: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x16a284u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16a288: 0x3e00008  jr          $ra
    ctx->pc = 0x16A288u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16A28Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A288u;
            // 0x16a28c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16A1F8u: goto label_16a1f8;
            case 0x16A200u: goto label_16a200;
            case 0x16A214u: goto label_16a214;
            case 0x16A238u: goto label_16a238;
            case 0x16A258u: goto label_16a258;
            case 0x16A270u: goto label_16a270;
            case 0x16A274u: goto label_16a274;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16A290u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
