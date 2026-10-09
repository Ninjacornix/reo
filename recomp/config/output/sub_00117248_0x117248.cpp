#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00117248
// Address: 0x117248 - 0x1172f0
void sub_00117248_0x117248(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00117248_0x117248");
#endif

    switch (ctx->pc) {
        case 0x117260u: goto label_117260;
        case 0x117278u: goto label_117278;
        case 0x1172bcu: goto label_1172bc;
        case 0x1172d8u: goto label_1172d8;
        default: break;
    }

    ctx->pc = 0x117248u;

    // 0x117248: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x117248u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11724c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11724cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x117250: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x117250u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x117254: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x117254u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x117258: 0xc047598  jal         func_11D660
    ctx->pc = 0x117258u;
    SET_GPR_U32(ctx, 31, 0x117260u);
    ctx->pc = 0x11725Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117258u;
            // 0x11725c: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117260u; }
        if (ctx->pc != 0x117260u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117260u; }
        if (ctx->pc != 0x117260u) { return; }
    }
    ctx->pc = 0x117260u;
label_117260:
    // 0x117260: 0x8e240008  lw          $a0, 0x8($s1)
    ctx->pc = 0x117260u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x117264: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x117264u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117268: 0x18800019  blez        $a0, . + 4 + (0x19 << 2)
    ctx->pc = 0x117268u;
    {
        const bool branch_taken_0x117268 = (GPR_S64(ctx, 4) <= 0);
        ctx->pc = 0x11726Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117268u;
            // 0x11726c: 0x8e300004  lw          $s0, 0x4($s1) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117268) {
            ctx->pc = 0x1172D0u;
            goto label_1172d0;
        }
    }
    ctx->pc = 0x117270u;
    // 0x117270: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x117270u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x117274: 0x0  nop
    ctx->pc = 0x117274u;
    // NOP
label_117278:
    // 0x117278: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x117278u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x11727c: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x11727cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x117280: 0x54400010  bnel        $v0, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x117280u;
    {
        const bool branch_taken_0x117280 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x117280) {
            ctx->pc = 0x117284u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x117280u;
            // 0x117284: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1172C4u;
            goto label_1172c4;
        }
    }
    ctx->pc = 0x117288u;
    // 0x117288: 0x31400  sll         $v0, $v1, 16
    ctx->pc = 0x117288u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x11728c: 0x34420005  ori         $v0, $v0, 0x5
    ctx->pc = 0x11728cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)5);
    // 0x117290: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x117290u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x117294: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x117294u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x117298: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x117298u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x11729c: 0x14650004  bne         $v1, $a1, . + 4 + (0x4 << 2)
    ctx->pc = 0x11729Cu;
    {
        const bool branch_taken_0x11729c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        ctx->pc = 0x1172A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11729Cu;
            // 0x1172a0: 0xae230000  sw          $v1, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11729c) {
            ctx->pc = 0x1172B0u;
            goto label_1172b0;
        }
    }
    ctx->pc = 0x1172A4u;
    // 0x1172a4: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x1172a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x1172a8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1172a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1172ac: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1172acu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
label_1172b0:
    // 0x1172b0: 0xae100014  sw          $s0, 0x14($s0)
    ctx->pc = 0x1172b0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 16));
    // 0x1172b4: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x1172B4u;
    SET_GPR_U32(ctx, 31, 0x1172BCu);
    ctx->pc = 0x1172B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1172B4u;
            // 0x1172b8: 0xae030018  sw          $v1, 0x18($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1172BCu; }
        if (ctx->pc != 0x1172BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1172BCu; }
        if (ctx->pc != 0x1172BCu) { return; }
    }
    ctx->pc = 0x1172BCu;
label_1172bc:
    // 0x1172bc: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1172BCu;
    {
        const bool branch_taken_0x1172bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1172C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1172BCu;
            // 0x1172c0: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1172bc) {
            ctx->pc = 0x1172DCu;
            goto label_1172dc;
        }
    }
    ctx->pc = 0x1172C4u;
label_1172c4:
    // 0x1172c4: 0x64102a  slt         $v0, $v1, $a0
    ctx->pc = 0x1172c4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1172c8: 0x1440ffeb  bnez        $v0, . + 4 + (-0x15 << 2)
    ctx->pc = 0x1172C8u;
    {
        const bool branch_taken_0x1172c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1172CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1172C8u;
            // 0x1172cc: 0x26100040  addiu       $s0, $s0, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1172c8) {
            ctx->pc = 0x117278u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_117278;
        }
    }
    ctx->pc = 0x1172D0u;
label_1172d0:
    // 0x1172d0: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x1172D0u;
    SET_GPR_U32(ctx, 31, 0x1172D8u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1172D8u; }
        if (ctx->pc != 0x1172D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1172D8u; }
        if (ctx->pc != 0x1172D8u) { return; }
    }
    ctx->pc = 0x1172D8u;
label_1172d8:
    // 0x1172d8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1172d8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1172dc:
    // 0x1172dc: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1172dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1172e0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1172e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1172e4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1172e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1172e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1172E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1172ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1172E8u;
            // 0x1172ec: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x117260u: goto label_117260;
            case 0x117278u: goto label_117278;
            case 0x1172B0u: goto label_1172b0;
            case 0x1172BCu: goto label_1172bc;
            case 0x1172C4u: goto label_1172c4;
            case 0x1172D0u: goto label_1172d0;
            case 0x1172D8u: goto label_1172d8;
            case 0x1172DCu: goto label_1172dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1172F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
