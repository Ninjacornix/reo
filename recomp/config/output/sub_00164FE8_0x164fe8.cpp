#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164FE8
// Address: 0x164fe8 - 0x16509c
void sub_00164FE8_0x164fe8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164FE8_0x164fe8");
#endif

    switch (ctx->pc) {
        case 0x165038u: goto label_165038;
        case 0x165048u: goto label_165048;
        case 0x165068u: goto label_165068;
        default: break;
    }

    ctx->pc = 0x164fe8u;

    // 0x164fe8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x164fe8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x164fec: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x164fecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x164ff0: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x164ff0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164ff4: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x164ff4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x164ff8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x164ff8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164ffc: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x164ffcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x165000: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x165000u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165004: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x165004u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x165008: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x165008u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16500c: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x16500cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x165010: 0x2a420120  slti        $v0, $s2, 0x120
    ctx->pc = 0x165010u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)288) ? 1 : 0);
    // 0x165014: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x165014u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x165018: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x165018u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16501c: 0xae600000  sw          $zero, 0x0($s3)
    ctx->pc = 0x16501cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 0));
    // 0x165020: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x165020u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165024: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x165024u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165028: 0x14400014  bnez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x165028u;
    {
        const bool branch_taken_0x165028 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16502Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165028u;
            // 0x16502c: 0x8e141b74  lw          $s4, 0x1B74($s0) (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 7028)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165028) {
            ctx->pc = 0x16507Cu;
            goto label_16507c;
        }
    }
    ctx->pc = 0x165030u;
    // 0x165030: 0xc04cc6a  jal         func_1331A8
    ctx->pc = 0x165030u;
    SET_GPR_U32(ctx, 31, 0x165038u);
    ctx->pc = 0x1331A8u;
    if (runtime->hasFunction(0x1331A8u)) {
        auto targetFn = runtime->lookupFunction(0x1331A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165038u; }
        if (ctx->pc != 0x165038u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001331A8_0x1331a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165038u; }
        if (ctx->pc != 0x165038u) { return; }
    }
    ctx->pc = 0x165038u;
label_165038:
    // 0x165038: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x165038u;
    {
        const bool branch_taken_0x165038 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16503Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165038u;
            // 0x16503c: 0x8fa30000  lw          $v1, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165038) {
            ctx->pc = 0x16506Cu;
            goto label_16506c;
        }
    }
    ctx->pc = 0x165040u;
    // 0x165040: 0xc05a660  jal         func_169980
    ctx->pc = 0x165040u;
    SET_GPR_U32(ctx, 31, 0x165048u);
    ctx->pc = 0x165044u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165040u;
            // 0x165044: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169980u;
    if (runtime->hasFunction(0x169980u)) {
        auto targetFn = runtime->lookupFunction(0x169980u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165048u; }
        if (ctx->pc != 0x165048u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169980_0x169980(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165048u; }
        if (ctx->pc != 0x165048u) { return; }
    }
    ctx->pc = 0x165048u;
label_165048:
    // 0x165048: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x165048u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16504c: 0x2842006c  slti        $v0, $v0, 0x6C
    ctx->pc = 0x16504cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)108) ? 1 : 0);
    // 0x165050: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x165050u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165054: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x165054u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165058: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x165058u;
    {
        const bool branch_taken_0x165058 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16505Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165058u;
            // 0x16505c: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165058) {
            ctx->pc = 0x16506Cu;
            goto label_16506c;
        }
    }
    ctx->pc = 0x165060u;
    // 0x165060: 0xc059428  jal         func_1650A0
    ctx->pc = 0x165060u;
    SET_GPR_U32(ctx, 31, 0x165068u);
    ctx->pc = 0x1650A0u;
    if (runtime->hasFunction(0x1650A0u)) {
        auto targetFn = runtime->lookupFunction(0x1650A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165068u; }
        if (ctx->pc != 0x165068u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001650A0_0x1650a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165068u; }
        if (ctx->pc != 0x165068u) { return; }
    }
    ctx->pc = 0x165068u;
label_165068:
    // 0x165068: 0x511823  subu        $v1, $v0, $s1
    ctx->pc = 0x165068u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
label_16506c:
    // 0x16506c: 0x3c020016  lui         $v0, 0x16
    ctx->pc = 0x16506cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)22 << 16));
    // 0x165070: 0xae630000  sw          $v1, 0x0($s3)
    ctx->pc = 0x165070u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x165074: 0x24424ce0  addiu       $v0, $v0, 0x4CE0
    ctx->pc = 0x165074u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19680));
    // 0x165078: 0xae82003c  sw          $v0, 0x3C($s4)
    ctx->pc = 0x165078u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 60), GPR_U32(ctx, 2));
label_16507c:
    // 0x16507c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x16507cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x165080: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x165080u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x165084: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x165084u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x165088: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x165088u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16508c: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x16508cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x165090: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x165090u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x165094: 0x3e00008  jr          $ra
    ctx->pc = 0x165094u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x165098u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165094u;
            // 0x165098: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x165038u: goto label_165038;
            case 0x165048u: goto label_165048;
            case 0x165068u: goto label_165068;
            case 0x16506Cu: goto label_16506c;
            case 0x16507Cu: goto label_16507c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16509Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
