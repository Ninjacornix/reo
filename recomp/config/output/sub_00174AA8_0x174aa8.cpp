#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00174AA8
// Address: 0x174aa8 - 0x174b28
void sub_00174AA8_0x174aa8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00174AA8_0x174aa8");
#endif

    switch (ctx->pc) {
        case 0x174ad0u: goto label_174ad0;
        case 0x174ae4u: goto label_174ae4;
        default: break;
    }

    ctx->pc = 0x174aa8u;

    // 0x174aa8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x174aa8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x174aac: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x174aacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x174ab0: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x174ab0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174ab4: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x174ab4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x174ab8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x174ab8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x174abc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x174abcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x174ac0: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x174ac0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174ac4: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x174ac4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x174ac8: 0xc05df24  jal         func_177C90
    ctx->pc = 0x174AC8u;
    SET_GPR_U32(ctx, 31, 0x174AD0u);
    ctx->pc = 0x174ACCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174AC8u;
            // 0x174acc: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177C90u;
    if (runtime->hasFunction(0x177C90u)) {
        auto targetFn = runtime->lookupFunction(0x177C90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174AD0u; }
        if (ctx->pc != 0x174AD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177C90_0x177c90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174AD0u; }
        if (ctx->pc != 0x174AD0u) { return; }
    }
    ctx->pc = 0x174AD0u;
label_174ad0:
    // 0x174ad0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x174ad0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174ad4: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x174AD4u;
    {
        const bool branch_taken_0x174ad4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x174AD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174AD4u;
            // 0x174ad8: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174ad4) {
            ctx->pc = 0x174B08u;
            goto label_174b08;
        }
    }
    ctx->pc = 0x174ADCu;
    // 0x174adc: 0xc05d58a  jal         func_175628
    ctx->pc = 0x174ADCu;
    SET_GPR_U32(ctx, 31, 0x174AE4u);
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174AE4u; }
        if (ctx->pc != 0x174AE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174AE4u; }
        if (ctx->pc != 0x174AE4u) { return; }
    }
    ctx->pc = 0x174AE4u;
label_174ae4:
    // 0x174ae4: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x174ae4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174ae8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x174ae8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x174aec: 0x54620007  bnel        $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x174AECu;
    {
        const bool branch_taken_0x174aec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x174aec) {
            ctx->pc = 0x174AF0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x174AECu;
            // 0x174af0: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x174B0Cu;
            goto label_174b0c;
        }
    }
    ctx->pc = 0x174AF4u;
    // 0x174af4: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x174af4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x174af8: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x174af8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x174afc: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x174AFCu;
    {
        const bool branch_taken_0x174afc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x174B00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174AFCu;
            // 0x174b00: 0x2c420001  sltiu       $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x174afc) {
            ctx->pc = 0x174B10u;
            goto label_174b10;
        }
    }
    ctx->pc = 0x174B04u;
    // 0x174b04: 0x0  nop
    ctx->pc = 0x174b04u;
    // NOP
label_174b08:
    // 0x174b08: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x174b08u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
label_174b0c:
    // 0x174b0c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x174b0cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_174b10:
    // 0x174b10: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x174b10u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x174b14: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x174b14u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x174b18: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x174b18u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x174b1c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x174b1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x174b20: 0x3e00008  jr          $ra
    ctx->pc = 0x174B20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x174B24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174B20u;
            // 0x174b24: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x174AD0u: goto label_174ad0;
            case 0x174AE4u: goto label_174ae4;
            case 0x174B08u: goto label_174b08;
            case 0x174B0Cu: goto label_174b0c;
            case 0x174B10u: goto label_174b10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x174B28u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
