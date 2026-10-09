#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D5918
// Address: 0x1d5918 - 0x1d59c8
void sub_001D5918_0x1d5918(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D5918_0x1d5918");
#endif

    switch (ctx->pc) {
        case 0x1d5964u: goto label_1d5964;
        case 0x1d596cu: goto label_1d596c;
        case 0x1d5978u: goto label_1d5978;
        case 0x1d598cu: goto label_1d598c;
        case 0x1d599cu: goto label_1d599c;
        default: break;
    }

    ctx->pc = 0x1d5918u;

    // 0x1d5918: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1d5918u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1d591c: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x1d591cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5920: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x1d5920u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1d5924: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d5924u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d5928: 0x3c110023  lui         $s1, 0x23
    ctx->pc = 0x1d5928u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)35 << 16));
    // 0x1d592c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1d592cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1d5930: 0x8e246998  lw          $a0, 0x6998($s1)
    ctx->pc = 0x1d5930u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 27032)));
    // 0x1d5934: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1d5934u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5938: 0x1082001a  beq         $a0, $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1D5938u;
    {
        const bool branch_taken_0x1d5938 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D593Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5938u;
            // 0x1d593c: 0xffbf0020  sd          $ra, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5938) {
            ctx->pc = 0x1D59A4u;
            goto label_1d59a4;
        }
    }
    ctx->pc = 0x1D5940u;
    // 0x1d5940: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D5940u;
    {
        const bool branch_taken_0x1d5940 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d5940) {
            ctx->pc = 0x1D595Cu;
            goto label_1d595c;
        }
    }
    ctx->pc = 0x1D5948u;
    // 0x1d5948: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d5948u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d594c: 0x1062000c  beq         $v1, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1D594Cu;
    {
        const bool branch_taken_0x1d594c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D5950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D594Cu;
            // 0x1d5950: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d594c) {
            ctx->pc = 0x1D5980u;
            goto label_1d5980;
        }
    }
    ctx->pc = 0x1D5954u;
    // 0x1d5954: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1D5954u;
    {
        const bool branch_taken_0x1d5954 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5958u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5954u;
            // 0x1d5958: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5954) {
            ctx->pc = 0x1D59A8u;
            goto label_1d59a8;
        }
    }
    ctx->pc = 0x1D595Cu;
label_1d595c:
    // 0x1d595c: 0xc045198  jal         func_114660
    ctx->pc = 0x1D595Cu;
    SET_GPR_U32(ctx, 31, 0x1D5964u);
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5964u; }
        if (ctx->pc != 0x1D5964u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5964u; }
        if (ctx->pc != 0x1D5964u) { return; }
    }
    ctx->pc = 0x1D5964u;
label_1d5964:
    // 0x1d5964: 0xc075672  jal         func_1D59C8
    ctx->pc = 0x1D5964u;
    SET_GPR_U32(ctx, 31, 0x1D596Cu);
    ctx->pc = 0x1D59C8u;
    if (runtime->hasFunction(0x1D59C8u)) {
        auto targetFn = runtime->lookupFunction(0x1D59C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D596Cu; }
        if (ctx->pc != 0x1D596Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D59C8_0x1d59c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D596Cu; }
        if (ctx->pc != 0x1D596Cu) { return; }
    }
    ctx->pc = 0x1D596Cu;
label_1d596c:
    // 0x1d596c: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x1d596cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x1d5970: 0xc045190  jal         func_114640
    ctx->pc = 0x1D5970u;
    SET_GPR_U32(ctx, 31, 0x1D5978u);
    ctx->pc = 0x1D5974u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5970u;
            // 0x1d5974: 0x8e246998  lw          $a0, 0x6998($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 27032)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5978u; }
        if (ctx->pc != 0x1D5978u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5978u; }
        if (ctx->pc != 0x1D5978u) { return; }
    }
    ctx->pc = 0x1D5978u;
label_1d5978:
    // 0x1d5978: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1D5978u;
    {
        const bool branch_taken_0x1d5978 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D597Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5978u;
            // 0x1d597c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5978) {
            ctx->pc = 0x1D59A4u;
            goto label_1d59a4;
        }
    }
    ctx->pc = 0x1D5980u;
label_1d5980:
    // 0x1d5980: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1d5980u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1d5984: 0xc045ef8  jal         func_117BE0
    ctx->pc = 0x1D5984u;
    SET_GPR_U32(ctx, 31, 0x1D598Cu);
    ctx->pc = 0x1D5988u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5984u;
            // 0x1d5988: 0x248428e0  addiu       $a0, $a0, 0x28E0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10464));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117BE0u;
    if (runtime->hasFunction(0x117BE0u)) {
        auto targetFn = runtime->lookupFunction(0x117BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D598Cu; }
        if (ctx->pc != 0x1D598Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117BE0_0x117be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D598Cu; }
        if (ctx->pc != 0x1D598Cu) { return; }
    }
    ctx->pc = 0x1D598Cu;
label_1d598c:
    // 0x1d598c: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D598Cu;
    {
        const bool branch_taken_0x1d598c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d598c) {
            ctx->pc = 0x1D5990u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1D598Cu;
            // 0x1d5990: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1D59A4u;
            goto label_1d59a4;
        }
    }
    ctx->pc = 0x1D5994u;
    // 0x1d5994: 0xc075672  jal         func_1D59C8
    ctx->pc = 0x1D5994u;
    SET_GPR_U32(ctx, 31, 0x1D599Cu);
    ctx->pc = 0x1D59C8u;
    if (runtime->hasFunction(0x1D59C8u)) {
        auto targetFn = runtime->lookupFunction(0x1D59C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D599Cu; }
        if (ctx->pc != 0x1D599Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D59C8_0x1d59c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D599Cu; }
        if (ctx->pc != 0x1D599Cu) { return; }
    }
    ctx->pc = 0x1D599Cu;
label_1d599c:
    // 0x1d599c: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x1d599cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x1d59a0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d59a0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d59a4:
    // 0x1d59a4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d59a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1d59a8:
    // 0x1d59a8: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1d59a8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d59ac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1d59acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d59b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D59B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D59B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D59B0u;
            // 0x1d59b4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D595Cu: goto label_1d595c;
            case 0x1D5964u: goto label_1d5964;
            case 0x1D596Cu: goto label_1d596c;
            case 0x1D5978u: goto label_1d5978;
            case 0x1D5980u: goto label_1d5980;
            case 0x1D598Cu: goto label_1d598c;
            case 0x1D599Cu: goto label_1d599c;
            case 0x1D59A4u: goto label_1d59a4;
            case 0x1D59A8u: goto label_1d59a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D59B8u;
    // 0x1d59b8: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d59b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d59bc: 0x8045194  j           func_114650
    ctx->pc = 0x1D59BCu;
    ctx->pc = 0x1D59C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D59BCu;
            // 0x1d59c0: 0x8c446998  lw          $a0, 0x6998($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 27032)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114650u;
    if (runtime->hasFunction(0x114650u)) {
        auto targetFn = runtime->lookupFunction(0x114650u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114650_0x114650(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1D59C4u;
    // 0x1d59c4: 0x0  nop
    ctx->pc = 0x1d59c4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
