#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001458D8
// Address: 0x1458d8 - 0x1459e8
void sub_001458D8_0x1458d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001458D8_0x1458d8");
#endif

    switch (ctx->pc) {
        case 0x145930u: goto label_145930;
        case 0x145948u: goto label_145948;
        case 0x1459b8u: goto label_1459b8;
        default: break;
    }

    ctx->pc = 0x1458d8u;

    // 0x1458d8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1458d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1458dc: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x1458dcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x1458e0: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x1458e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1458e4: 0x34422010  ori         $v0, $v0, 0x2010
    ctx->pc = 0x1458e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8208);
    // 0x1458e8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1458e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1458ec: 0x3c068000  lui         $a2, 0x8000
    ctx->pc = 0x1458ecu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32768 << 16));
    // 0x1458f0: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1458f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1458f4: 0x34c64000  ori         $a2, $a2, 0x4000
    ctx->pc = 0x1458f4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)16384);
    // 0x1458f8: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1458f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1458fc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1458fcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145900: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x145900u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145904: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x145904u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145908: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x145908u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14590c: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x14590cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x145910: 0x661824  and         $v1, $v1, $a2
    ctx->pc = 0x145910u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 6));
    // 0x145914: 0x1462001b  bne         $v1, $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x145914u;
    {
        const bool branch_taken_0x145914 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x145918u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145914u;
            // 0x145918: 0x3c120023  lui         $s2, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145914) {
            ctx->pc = 0x145984u;
            goto label_145984;
        }
    }
    ctx->pc = 0x14591Cu;
    // 0x14591c: 0x8e0210a0  lw          $v0, 0x10A0($s0)
    ctx->pc = 0x14591cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4256)));
    // 0x145920: 0x14400019  bnez        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x145920u;
    {
        const bool branch_taken_0x145920 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x145924u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145920u;
            // 0x145924: 0x3c024000  lui         $v0, 0x4000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16384 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145920) {
            ctx->pc = 0x145988u;
            goto label_145988;
        }
    }
    ctx->pc = 0x145928u;
    // 0x145928: 0x3c120023  lui         $s2, 0x23
    ctx->pc = 0x145928u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)35 << 16));
    // 0x14592c: 0x0  nop
    ctx->pc = 0x14592cu;
    // NOP
label_145930:
    // 0x145930: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x145930u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145934: 0x28421389  slti        $v0, $v0, 0x1389
    ctx->pc = 0x145934u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)5001) ? 1 : 0);
    // 0x145938: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x145938u;
    {
        const bool branch_taken_0x145938 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x14593Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145938u;
            // 0x14593c: 0x24e70001  addiu       $a3, $a3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145938) {
            ctx->pc = 0x14594Cu;
            goto label_14594c;
        }
    }
    ctx->pc = 0x145940u;
    // 0x145940: 0xc051ff8  jal         func_147FE0
    ctx->pc = 0x145940u;
    SET_GPR_U32(ctx, 31, 0x145948u);
    ctx->pc = 0x145944u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145940u;
            // 0x145944: 0x8e040870  lw          $a0, 0x870($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2160)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147FE0u;
    if (runtime->hasFunction(0x147FE0u)) {
        auto targetFn = runtime->lookupFunction(0x147FE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145948u; }
        if (ctx->pc != 0x145948u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147FE0_0x147fe0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145948u; }
        if (ctx->pc != 0x145948u) { return; }
    }
    ctx->pc = 0x145948u;
label_145948:
    // 0x145948: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x145948u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_14594c:
    // 0x14594c: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x14594cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x145950: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x145950u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x145954: 0x34632010  ori         $v1, $v1, 0x2010
    ctx->pc = 0x145954u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)8208);
    // 0x145958: 0x34844000  ori         $a0, $a0, 0x4000
    ctx->pc = 0x145958u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)16384);
    // 0x14595c: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x14595cu;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x145960: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x145960u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x145964: 0x441024  and         $v0, $v0, $a0
    ctx->pc = 0x145964u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
    // 0x145968: 0x14450007  bne         $v0, $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x145968u;
    {
        const bool branch_taken_0x145968 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        ctx->pc = 0x14596Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145968u;
            // 0x14596c: 0x3c024000  lui         $v0, 0x4000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16384 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145968) {
            ctx->pc = 0x145988u;
            goto label_145988;
        }
    }
    ctx->pc = 0x145970u;
    // 0x145970: 0x8e0210a0  lw          $v0, 0x10A0($s0)
    ctx->pc = 0x145970u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4256)));
    // 0x145974: 0x1040ffee  beqz        $v0, . + 4 + (-0x12 << 2)
    ctx->pc = 0x145974u;
    {
        const bool branch_taken_0x145974 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x145978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145974u;
            // 0x145978: 0x3c024000  lui         $v0, 0x4000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16384 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145974) {
            ctx->pc = 0x145930u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_145930;
        }
    }
    ctx->pc = 0x14597Cu;
    // 0x14597c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x14597Cu;
    {
        const bool branch_taken_0x14597c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x145980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14597Cu;
            // 0x145980: 0x3c031000  lui         $v1, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14597c) {
            ctx->pc = 0x14598Cu;
            goto label_14598c;
        }
    }
    ctx->pc = 0x145984u;
label_145984:
    // 0x145984: 0x3c024000  lui         $v0, 0x4000
    ctx->pc = 0x145984u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16384 << 16));
label_145988:
    // 0x145988: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x145988u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
label_14598c:
    // 0x14598c: 0x2221025  or          $v0, $s1, $v0
    ctx->pc = 0x14598cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) | GPR_U64(ctx, 2));
    // 0x145990: 0x34632000  ori         $v1, $v1, 0x2000
    ctx->pc = 0x145990u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)8192);
    // 0x145994: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x145994u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2)); // MMIO: 0x10000000
    // 0x145998: 0x22f02  srl         $a1, $v0, 28
    ctx->pc = 0x145998u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 2), 28));
    // 0x14599c: 0x2642a6f8  addiu       $v0, $s2, -0x5908
    ctx->pc = 0x14599cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 4294944504));
    // 0x1459a0: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x1459a0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1459a4: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x1459a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1459a8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1459a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1459ac: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x1459acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1459b0: 0xc0514f0  jal         func_1453C0
    ctx->pc = 0x1459B0u;
    SET_GPR_U32(ctx, 31, 0x1459B8u);
    ctx->pc = 0x1459B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1459B0u;
            // 0x1459b4: 0xae020830  sw          $v0, 0x830($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 2096), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1453C0u;
    if (runtime->hasFunction(0x1453C0u)) {
        auto targetFn = runtime->lookupFunction(0x1453C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1459B8u; }
        if (ctx->pc != 0x1459B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001453C0_0x1453c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1459B8u; }
        if (ctx->pc != 0x1459B8u) { return; }
    }
    ctx->pc = 0x1459B8u;
label_1459b8:
    // 0x1459b8: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1459b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1459bc: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1459bcu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1459c0: 0x24030020  addiu       $v1, $zero, 0x20
    ctx->pc = 0x1459c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1459c4: 0xae030854  sw          $v1, 0x854($s0)
    ctx->pc = 0x1459c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2132), GPR_U32(ctx, 3));
    // 0x1459c8: 0xae020850  sw          $v0, 0x850($s0)
    ctx->pc = 0x1459c8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2128), GPR_U32(ctx, 2));
    // 0x1459cc: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1459ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1459d0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1459d0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1459d4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1459d4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1459d8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1459d8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1459dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1459DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1459E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1459DCu;
            // 0x1459e0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x145930u: goto label_145930;
            case 0x145948u: goto label_145948;
            case 0x14594Cu: goto label_14594c;
            case 0x145984u: goto label_145984;
            case 0x145988u: goto label_145988;
            case 0x14598Cu: goto label_14598c;
            case 0x1459B8u: goto label_1459b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1459E4u;
    // 0x1459e4: 0x0  nop
    ctx->pc = 0x1459e4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
