#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C0710
// Address: 0x1c0710 - 0x1c09d0
void sub_001C0710_0x1c0710(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C0710_0x1c0710");
#endif

    switch (ctx->pc) {
        case 0x1c0794u: goto label_1c0794;
        case 0x1c080cu: goto label_1c080c;
        case 0x1c086cu: goto label_1c086c;
        case 0x1c0944u: goto label_1c0944;
        case 0x1c09b8u: goto label_1c09b8;
        default: break;
    }

    ctx->pc = 0x1c0710u;

    // 0x1c0710: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c0710u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c0714: 0x3c070023  lui         $a3, 0x23
    ctx->pc = 0x1c0714u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)35 << 16));
    // 0x1c0718: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c0718u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c071c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c071cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c0720: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c0720u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c0724: 0x24e75160  addiu       $a3, $a3, 0x5160
    ctx->pc = 0x1c0724u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 20832));
    // 0x1c0728: 0x8c286cf0  lw          $t0, 0x6CF0($at)
    ctx->pc = 0x1c0728u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 27888)));
    // 0x1c072c: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c072cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c0730: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1c0730u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c0734: 0x84080  sll         $t0, $t0, 2
    ctx->pc = 0x1c0734u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
    // 0x1c0738: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0738u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c073c: 0xe83821  addu        $a3, $a3, $t0
    ctx->pc = 0x1c073cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x1c0740: 0x8cf00000  lw          $s0, 0x0($a3)
    ctx->pc = 0x1c0740u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1c0744: 0xac236ce8  sw          $v1, 0x6CE8($at)
    ctx->pc = 0x1c0744u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27880), GPR_U32(ctx, 3));
    // 0x1c0748: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0748u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c074c: 0xac226c74  sw          $v0, 0x6C74($at)
    ctx->pc = 0x1c074cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27764), GPR_U32(ctx, 2));
    // 0x1c0750: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0750u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c0754: 0xac206c50  sw          $zero, 0x6C50($at)
    ctx->pc = 0x1c0754u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27728), GPR_U32(ctx, 0));
    // 0x1c0758: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0758u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c075c: 0xac206c54  sw          $zero, 0x6C54($at)
    ctx->pc = 0x1c075cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27732), GPR_U32(ctx, 0));
    // 0x1c0760: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0760u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c0764: 0xac246c64  sw          $a0, 0x6C64($at)
    ctx->pc = 0x1c0764u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27748), GPR_U32(ctx, 4));
    // 0x1c0768: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0768u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c076c: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1c076cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1c0770: 0xac256cec  sw          $a1, 0x6CEC($at)
    ctx->pc = 0x1c0770u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27884), GPR_U32(ctx, 5));
    // 0x1c0774: 0x24846c94  addiu       $a0, $a0, 0x6C94
    ctx->pc = 0x1c0774u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 27796));
    // 0x1c0778: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0778u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c077c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c077cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c0780: 0xac266ce0  sw          $a2, 0x6CE0($at)
    ctx->pc = 0x1c0780u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27872), GPR_U32(ctx, 6));
    // 0x1c0784: 0x24a50640  addiu       $a1, $a1, 0x640
    ctx->pc = 0x1c0784u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1600));
    // 0x1c0788: 0x8e060010  lw          $a2, 0x10($s0)
    ctx->pc = 0x1c0788u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1c078c: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1C078Cu;
    SET_GPR_U32(ctx, 31, 0x1C0794u);
    ctx->pc = 0x1C0790u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C078Cu;
            // 0x1c0790: 0xc0382d  daddu       $a3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0794u; }
        if (ctx->pc != 0x1C0794u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0794u; }
        if (ctx->pc != 0x1C0794u) { return; }
    }
    ctx->pc = 0x1C0794u;
label_1c0794:
    // 0x1c0794: 0x8e030018  lw          $v1, 0x18($s0)
    ctx->pc = 0x1c0794u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x1c0798: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0798u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c079c: 0xac236cd8  sw          $v1, 0x6CD8($at)
    ctx->pc = 0x1c079cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27864), GPR_U32(ctx, 3));
    // 0x1c07a0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c07a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c07a4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c07a4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c07a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1C07A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C07ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C07A8u;
            // 0x1c07ac: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C0794u: goto label_1c0794;
            case 0x1C0804u: goto label_1c0804;
            case 0x1C080Cu: goto label_1c080c;
            case 0x1C083Cu: goto label_1c083c;
            case 0x1C0848u: goto label_1c0848;
            case 0x1C0854u: goto label_1c0854;
            case 0x1C0864u: goto label_1c0864;
            case 0x1C086Cu: goto label_1c086c;
            case 0x1C089Cu: goto label_1c089c;
            case 0x1C08BCu: goto label_1c08bc;
            case 0x1C08D4u: goto label_1c08d4;
            case 0x1C08E4u: goto label_1c08e4;
            case 0x1C0914u: goto label_1c0914;
            case 0x1C091Cu: goto label_1c091c;
            case 0x1C092Cu: goto label_1c092c;
            case 0x1C093Cu: goto label_1c093c;
            case 0x1C0944u: goto label_1c0944;
            case 0x1C0960u: goto label_1c0960;
            case 0x1C097Cu: goto label_1c097c;
            case 0x1C0984u: goto label_1c0984;
            case 0x1C09A0u: goto label_1c09a0;
            case 0x1C09A8u: goto label_1c09a8;
            case 0x1C09ACu: goto label_1c09ac;
            case 0x1C09B0u: goto label_1c09b0;
            case 0x1C09B8u: goto label_1c09b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C07B0u;
    // 0x1c07b0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1c07b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1c07b4: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x1c07b4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x1c07b8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1c07b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1c07bc: 0x24a55160  addiu       $a1, $a1, 0x5160
    ctx->pc = 0x1c07bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 20832));
    // 0x1c07c0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c07c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c07c4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1c07c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c07c8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c07c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c07cc: 0x8c8600a0  lw          $a2, 0xA0($a0)
    ctx->pc = 0x1c07ccu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 160)));
    // 0x1c07d0: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1c07d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c07d4: 0x63080  sll         $a2, $a2, 2
    ctx->pc = 0x1c07d4u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x1c07d8: 0xa62821  addu        $a1, $a1, $a2
    ctx->pc = 0x1c07d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1c07dc: 0x8cb00000  lw          $s0, 0x0($a1)
    ctx->pc = 0x1c07dcu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1c07e0: 0x10620056  beq         $v1, $v0, . + 4 + (0x56 << 2)
    ctx->pc = 0x1C07E0u;
    {
        const bool branch_taken_0x1c07e0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C07E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C07E0u;
            // 0x1c07e4: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c07e0) {
            ctx->pc = 0x1C093Cu;
            goto label_1c093c;
        }
    }
    ctx->pc = 0x1C07E8u;
    // 0x1c07e8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c07e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c07ec: 0x1062001d  beq         $v1, $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1C07ECu;
    {
        const bool branch_taken_0x1c07ec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1c07ec) {
            ctx->pc = 0x1C0864u;
            goto label_1c0864;
        }
    }
    ctx->pc = 0x1C07F4u;
    // 0x1c07f4: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C07F4u;
    {
        const bool branch_taken_0x1c07f4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c07f4) {
            ctx->pc = 0x1C0804u;
            goto label_1c0804;
        }
    }
    ctx->pc = 0x1C07FCu;
    // 0x1c07fc: 0x1000006c  b           . + 4 + (0x6C << 2)
    ctx->pc = 0x1C07FCu;
    {
        const bool branch_taken_0x1c07fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0800u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C07FCu;
            // 0x1c0800: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c07fc) {
            ctx->pc = 0x1C09B0u;
            goto label_1c09b0;
        }
    }
    ctx->pc = 0x1C0804u;
label_1c0804:
    // 0x1c0804: 0xc06fe10  jal         func_1BF840
    ctx->pc = 0x1C0804u;
    SET_GPR_U32(ctx, 31, 0x1C080Cu);
    ctx->pc = 0x1BF840u;
    if (runtime->hasFunction(0x1BF840u)) {
        auto targetFn = runtime->lookupFunction(0x1BF840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C080Cu; }
        if (ctx->pc != 0x1C080Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF840_0x1bf840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C080Cu; }
        if (ctx->pc != 0x1C080Cu) { return; }
    }
    ctx->pc = 0x1C080Cu;
label_1c080c:
    // 0x1c080c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1c080cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c0810: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1C0810u;
    {
        const bool branch_taken_0x1c0810 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C0814u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0810u;
            // 0x1c0814: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0810) {
            ctx->pc = 0x1C0854u;
            goto label_1c0854;
        }
    }
    ctx->pc = 0x1C0818u;
    // 0x1c0818: 0x1043000e  beq         $v0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1C0818u;
    {
        const bool branch_taken_0x1c0818 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0818) {
            ctx->pc = 0x1C0854u;
            goto label_1c0854;
        }
    }
    ctx->pc = 0x1C0820u;
    // 0x1c0820: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c0820u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c0824: 0x10430008  beq         $v0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C0824u;
    {
        const bool branch_taken_0x1c0824 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0824) {
            ctx->pc = 0x1C0848u;
            goto label_1c0848;
        }
    }
    ctx->pc = 0x1C082Cu;
    // 0x1c082c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C082Cu;
    {
        const bool branch_taken_0x1c082c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c082c) {
            ctx->pc = 0x1C083Cu;
            goto label_1c083c;
        }
    }
    ctx->pc = 0x1C0834u;
    // 0x1c0834: 0x1000005d  b           . + 4 + (0x5D << 2)
    ctx->pc = 0x1C0834u;
    {
        const bool branch_taken_0x1c0834 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0834) {
            ctx->pc = 0x1C09ACu;
            goto label_1c09ac;
        }
    }
    ctx->pc = 0x1C083Cu;
label_1c083c:
    // 0x1c083c: 0x2402ff01  addiu       $v0, $zero, -0xFF
    ctx->pc = 0x1c083cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967041));
    // 0x1c0840: 0x1000005a  b           . + 4 + (0x5A << 2)
    ctx->pc = 0x1C0840u;
    {
        const bool branch_taken_0x1c0840 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0844u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0840u;
            // 0x1c0844: 0xae220024  sw          $v0, 0x24($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0840) {
            ctx->pc = 0x1C09ACu;
            goto label_1c09ac;
        }
    }
    ctx->pc = 0x1C0848u;
label_1c0848:
    // 0x1c0848: 0x2402ff02  addiu       $v0, $zero, -0xFE
    ctx->pc = 0x1c0848u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967042));
    // 0x1c084c: 0x10000057  b           . + 4 + (0x57 << 2)
    ctx->pc = 0x1C084Cu;
    {
        const bool branch_taken_0x1c084c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0850u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C084Cu;
            // 0x1c0850: 0xae220024  sw          $v0, 0x24($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c084c) {
            ctx->pc = 0x1C09ACu;
            goto label_1c09ac;
        }
    }
    ctx->pc = 0x1C0854u;
label_1c0854:
    // 0x1c0854: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1c0854u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1c0858: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c0858u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c085c: 0x10000053  b           . + 4 + (0x53 << 2)
    ctx->pc = 0x1C085Cu;
    {
        const bool branch_taken_0x1c085c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0860u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C085Cu;
            // 0x1c0860: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c085c) {
            ctx->pc = 0x1C09ACu;
            goto label_1c09ac;
        }
    }
    ctx->pc = 0x1C0864u;
label_1c0864:
    // 0x1c0864: 0xc06fe94  jal         func_1BFA50
    ctx->pc = 0x1C0864u;
    SET_GPR_U32(ctx, 31, 0x1C086Cu);
    ctx->pc = 0x1BFA50u;
    if (runtime->hasFunction(0x1BFA50u)) {
        auto targetFn = runtime->lookupFunction(0x1BFA50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C086Cu; }
        if (ctx->pc != 0x1C086Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BFA50_0x1bfa50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C086Cu; }
        if (ctx->pc != 0x1C086Cu) { return; }
    }
    ctx->pc = 0x1C086Cu;
label_1c086c:
    // 0x1c086c: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c086cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c0870: 0x1043002e  beq         $v0, $v1, . + 4 + (0x2E << 2)
    ctx->pc = 0x1C0870u;
    {
        const bool branch_taken_0x1c0870 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C0874u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0870u;
            // 0x1c0874: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0870) {
            ctx->pc = 0x1C092Cu;
            goto label_1c092c;
        }
    }
    ctx->pc = 0x1C0878u;
    // 0x1c0878: 0x10430028  beq         $v0, $v1, . + 4 + (0x28 << 2)
    ctx->pc = 0x1C0878u;
    {
        const bool branch_taken_0x1c0878 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0878) {
            ctx->pc = 0x1C091Cu;
            goto label_1c091c;
        }
    }
    ctx->pc = 0x1C0880u;
    // 0x1c0880: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c0880u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0884: 0x10430017  beq         $v0, $v1, . + 4 + (0x17 << 2)
    ctx->pc = 0x1C0884u;
    {
        const bool branch_taken_0x1c0884 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0884) {
            ctx->pc = 0x1C08E4u;
            goto label_1c08e4;
        }
    }
    ctx->pc = 0x1C088Cu;
    // 0x1c088c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C088Cu;
    {
        const bool branch_taken_0x1c088c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0890u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C088Cu;
            // 0x1c0890: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c088c) {
            ctx->pc = 0x1C089Cu;
            goto label_1c089c;
        }
    }
    ctx->pc = 0x1C0894u;
    // 0x1c0894: 0x10000045  b           . + 4 + (0x45 << 2)
    ctx->pc = 0x1C0894u;
    {
        const bool branch_taken_0x1c0894 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0894) {
            ctx->pc = 0x1C09ACu;
            goto label_1c09ac;
        }
    }
    ctx->pc = 0x1C089Cu;
label_1c089c:
    // 0x1c089c: 0x8e220088  lw          $v0, 0x88($s1)
    ctx->pc = 0x1c089cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 136)));
    // 0x1c08a0: 0x8c236ac0  lw          $v1, 0x6AC0($at)
    ctx->pc = 0x1c08a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 27328)));
    // 0x1c08a4: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C08A4u;
    {
        const bool branch_taken_0x1c08a4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1c08a4) {
            ctx->pc = 0x1C08BCu;
            goto label_1c08bc;
        }
    }
    ctx->pc = 0x1C08ACu;
    // 0x1c08ac: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x1c08acu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x1c08b0: 0x2402ff05  addiu       $v0, $zero, -0xFB
    ctx->pc = 0x1c08b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967045));
    // 0x1c08b4: 0x1000003d  b           . + 4 + (0x3D << 2)
    ctx->pc = 0x1C08B4u;
    {
        const bool branch_taken_0x1c08b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C08B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C08B4u;
            // 0x1c08b8: 0xae220024  sw          $v0, 0x24($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c08b4) {
            ctx->pc = 0x1C09ACu;
            goto label_1c09ac;
        }
    }
    ctx->pc = 0x1C08BCu;
label_1c08bc:
    // 0x1c08bc: 0x8e220090  lw          $v0, 0x90($s1)
    ctx->pc = 0x1c08bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 144)));
    // 0x1c08c0: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C08C0u;
    {
        const bool branch_taken_0x1c08c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c08c0) {
            ctx->pc = 0x1C08D4u;
            goto label_1c08d4;
        }
    }
    ctx->pc = 0x1C08C8u;
    // 0x1c08c8: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x1c08c8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x1c08cc: 0x10000037  b           . + 4 + (0x37 << 2)
    ctx->pc = 0x1C08CCu;
    {
        const bool branch_taken_0x1c08cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C08D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C08CCu;
            // 0x1c08d0: 0xae200024  sw          $zero, 0x24($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c08cc) {
            ctx->pc = 0x1C09ACu;
            goto label_1c09ac;
        }
    }
    ctx->pc = 0x1C08D4u;
label_1c08d4:
    // 0x1c08d4: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1c08d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1c08d8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c08d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c08dc: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x1C08DCu;
    {
        const bool branch_taken_0x1c08dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C08E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C08DCu;
            // 0x1c08e0: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c08dc) {
            ctx->pc = 0x1C09ACu;
            goto label_1c09ac;
        }
    }
    ctx->pc = 0x1C08E4u;
label_1c08e4:
    // 0x1c08e4: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x1c08e4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x1c08e8: 0x8e230014  lw          $v1, 0x14($s1)
    ctx->pc = 0x1c08e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1c08ec: 0x8e02005c  lw          $v0, 0x5C($s0)
    ctx->pc = 0x1c08ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 92)));
    // 0x1c08f0: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1c08f0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1c08f4: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1c08f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1c08f8: 0x8c630034  lw          $v1, 0x34($v1)
    ctx->pc = 0x1c08f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 52)));
    // 0x1c08fc: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1c08fcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1c0900: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C0900u;
    {
        const bool branch_taken_0x1c0900 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C0904u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0900u;
            // 0x1c0904: 0x2402ff04  addiu       $v0, $zero, -0xFC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967044));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0900) {
            ctx->pc = 0x1C0914u;
            goto label_1c0914;
        }
    }
    ctx->pc = 0x1C0908u;
    // 0x1c0908: 0x2402ff03  addiu       $v0, $zero, -0xFD
    ctx->pc = 0x1c0908u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967043));
    // 0x1c090c: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x1C090Cu;
    {
        const bool branch_taken_0x1c090c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C090Cu;
            // 0x1c0910: 0xae220024  sw          $v0, 0x24($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c090c) {
            ctx->pc = 0x1C09ACu;
            goto label_1c09ac;
        }
    }
    ctx->pc = 0x1C0914u;
label_1c0914:
    // 0x1c0914: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1C0914u;
    {
        const bool branch_taken_0x1c0914 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0918u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0914u;
            // 0x1c0918: 0xae220024  sw          $v0, 0x24($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0914) {
            ctx->pc = 0x1C09ACu;
            goto label_1c09ac;
        }
    }
    ctx->pc = 0x1C091Cu;
label_1c091c:
    // 0x1c091c: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x1c091cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x1c0920: 0x2402ff01  addiu       $v0, $zero, -0xFF
    ctx->pc = 0x1c0920u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967041));
    // 0x1c0924: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x1C0924u;
    {
        const bool branch_taken_0x1c0924 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0928u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0924u;
            // 0x1c0928: 0xae220024  sw          $v0, 0x24($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0924) {
            ctx->pc = 0x1C09ACu;
            goto label_1c09ac;
        }
    }
    ctx->pc = 0x1C092Cu;
label_1c092c:
    // 0x1c092c: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x1c092cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x1c0930: 0x2402ff00  addiu       $v0, $zero, -0x100
    ctx->pc = 0x1c0930u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c0934: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1C0934u;
    {
        const bool branch_taken_0x1c0934 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0938u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0934u;
            // 0x1c0938: 0xae220024  sw          $v0, 0x24($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0934) {
            ctx->pc = 0x1C09ACu;
            goto label_1c09ac;
        }
    }
    ctx->pc = 0x1C093Cu;
label_1c093c:
    // 0x1c093c: 0xc06fed0  jal         func_1BFB40
    ctx->pc = 0x1C093Cu;
    SET_GPR_U32(ctx, 31, 0x1C0944u);
    ctx->pc = 0x1BFB40u;
    if (runtime->hasFunction(0x1BFB40u)) {
        auto targetFn = runtime->lookupFunction(0x1BFB40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0944u; }
        if (ctx->pc != 0x1C0944u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BFB40_0x1bfb40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0944u; }
        if (ctx->pc != 0x1C0944u) { return; }
    }
    ctx->pc = 0x1C0944u;
label_1c0944:
    // 0x1c0944: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c0944u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0948: 0x1043000e  beq         $v0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1C0948u;
    {
        const bool branch_taken_0x1c0948 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c0948) {
            ctx->pc = 0x1C0984u;
            goto label_1c0984;
        }
    }
    ctx->pc = 0x1C0950u;
    // 0x1c0950: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0950u;
    {
        const bool branch_taken_0x1c0950 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0950) {
            ctx->pc = 0x1C0960u;
            goto label_1c0960;
        }
    }
    ctx->pc = 0x1C0958u;
    // 0x1c0958: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1C0958u;
    {
        const bool branch_taken_0x1c0958 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0958) {
            ctx->pc = 0x1C09ACu;
            goto label_1c09ac;
        }
    }
    ctx->pc = 0x1C0960u;
label_1c0960:
    // 0x1c0960: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x1c0960u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x1c0964: 0x8e23001c  lw          $v1, 0x1C($s1)
    ctx->pc = 0x1c0964u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x1c0968: 0x8e220088  lw          $v0, 0x88($s1)
    ctx->pc = 0x1c0968u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 136)));
    // 0x1c096c: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C096Cu;
    {
        const bool branch_taken_0x1c096c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1C0970u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C096Cu;
            // 0x1c0970: 0x2402ff00  addiu       $v0, $zero, -0x100 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c096c) {
            ctx->pc = 0x1C097Cu;
            goto label_1c097c;
        }
    }
    ctx->pc = 0x1C0974u;
    // 0x1c0974: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1C0974u;
    {
        const bool branch_taken_0x1c0974 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0974u;
            // 0x1c0978: 0xae200024  sw          $zero, 0x24($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0974) {
            ctx->pc = 0x1C09ACu;
            goto label_1c09ac;
        }
    }
    ctx->pc = 0x1C097Cu;
label_1c097c:
    // 0x1c097c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1C097Cu;
    {
        const bool branch_taken_0x1c097c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C097Cu;
            // 0x1c0980: 0xae220024  sw          $v0, 0x24($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c097c) {
            ctx->pc = 0x1C09ACu;
            goto label_1c09ac;
        }
    }
    ctx->pc = 0x1C0984u;
label_1c0984:
    // 0x1c0984: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x1c0984u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x1c0988: 0x24020013  addiu       $v0, $zero, 0x13
    ctx->pc = 0x1c0988u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x1c098c: 0x9623001c  lhu         $v1, 0x1C($s1)
    ctx->pc = 0x1c098cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x1c0990: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0990u;
    {
        const bool branch_taken_0x1c0990 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C0994u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0990u;
            // 0x1c0994: 0x2402ff01  addiu       $v0, $zero, -0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967041));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0990) {
            ctx->pc = 0x1C09A0u;
            goto label_1c09a0;
        }
    }
    ctx->pc = 0x1C0998u;
    // 0x1c0998: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0998u;
    {
        const bool branch_taken_0x1c0998 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C099Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0998u;
            // 0x1c099c: 0x2402ff00  addiu       $v0, $zero, -0x100 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0998) {
            ctx->pc = 0x1C09A8u;
            goto label_1c09a8;
        }
    }
    ctx->pc = 0x1C09A0u;
label_1c09a0:
    // 0x1c09a0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C09A0u;
    {
        const bool branch_taken_0x1c09a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C09A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C09A0u;
            // 0x1c09a4: 0xae220024  sw          $v0, 0x24($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c09a0) {
            ctx->pc = 0x1C09ACu;
            goto label_1c09ac;
        }
    }
    ctx->pc = 0x1C09A8u;
label_1c09a8:
    // 0x1c09a8: 0xae220024  sw          $v0, 0x24($s1)
    ctx->pc = 0x1c09a8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 2));
label_1c09ac:
    // 0x1c09ac: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1c09acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_1c09b0:
    // 0x1c09b0: 0xc070108  jal         func_1C0420
    ctx->pc = 0x1C09B0u;
    SET_GPR_U32(ctx, 31, 0x1C09B8u);
    ctx->pc = 0x1C0420u;
    if (runtime->hasFunction(0x1C0420u)) {
        auto targetFn = runtime->lookupFunction(0x1C0420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C09B8u; }
        if (ctx->pc != 0x1C09B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0420_0x1c0420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C09B8u; }
        if (ctx->pc != 0x1C09B8u) { return; }
    }
    ctx->pc = 0x1C09B8u;
label_1c09b8:
    // 0x1c09b8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1c09b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c09bc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c09bcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c09c0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c09c0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c09c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1C09C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C09C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C09C4u;
            // 0x1c09c8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C0794u: goto label_1c0794;
            case 0x1C0804u: goto label_1c0804;
            case 0x1C080Cu: goto label_1c080c;
            case 0x1C083Cu: goto label_1c083c;
            case 0x1C0848u: goto label_1c0848;
            case 0x1C0854u: goto label_1c0854;
            case 0x1C0864u: goto label_1c0864;
            case 0x1C086Cu: goto label_1c086c;
            case 0x1C089Cu: goto label_1c089c;
            case 0x1C08BCu: goto label_1c08bc;
            case 0x1C08D4u: goto label_1c08d4;
            case 0x1C08E4u: goto label_1c08e4;
            case 0x1C0914u: goto label_1c0914;
            case 0x1C091Cu: goto label_1c091c;
            case 0x1C092Cu: goto label_1c092c;
            case 0x1C093Cu: goto label_1c093c;
            case 0x1C0944u: goto label_1c0944;
            case 0x1C0960u: goto label_1c0960;
            case 0x1C097Cu: goto label_1c097c;
            case 0x1C0984u: goto label_1c0984;
            case 0x1C09A0u: goto label_1c09a0;
            case 0x1C09A8u: goto label_1c09a8;
            case 0x1C09ACu: goto label_1c09ac;
            case 0x1C09B0u: goto label_1c09b0;
            case 0x1C09B8u: goto label_1c09b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C09CCu;
    // 0x1c09cc: 0x0  nop
    ctx->pc = 0x1c09ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
