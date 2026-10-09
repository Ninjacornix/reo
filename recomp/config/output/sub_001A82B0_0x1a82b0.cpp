#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A82B0
// Address: 0x1a82b0 - 0x1a8450
void sub_001A82B0_0x1a82b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A82B0_0x1a82b0");
#endif

    switch (ctx->pc) {
        case 0x1a82ccu: goto label_1a82cc;
        case 0x1a8304u: goto label_1a8304;
        default: break;
    }

    ctx->pc = 0x1a82b0u;

    // 0x1a82b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a82b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a82b4: 0x28a10009  slti        $at, $a1, 0x9
    ctx->pc = 0x1a82b4u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0x1a82b8: 0x14200006  bnez        $at, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A82B8u;
    {
        const bool branch_taken_0x1a82b8 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A82BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A82B8u;
            // 0x1a82bc: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a82b8) {
            ctx->pc = 0x1A82D4u;
            goto label_1a82d4;
        }
    }
    ctx->pc = 0x1A82C0u;
    // 0x1a82c0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a82c0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a82c4: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A82C4u;
    SET_GPR_U32(ctx, 31, 0x1A82CCu);
    ctx->pc = 0x1A82C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A82C4u;
            // 0x1a82c8: 0x248424b0  addiu       $a0, $a0, 0x24B0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9392));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A82CCu; }
        if (ctx->pc != 0x1A82CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A82CCu; }
        if (ctx->pc != 0x1A82CCu) { return; }
    }
    ctx->pc = 0x1A82CCu;
label_1a82cc:
    // 0x1a82cc: 0x1000005b  b           . + 4 + (0x5B << 2)
    ctx->pc = 0x1A82CCu;
    {
        const bool branch_taken_0x1a82cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A82D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A82CCu;
            // 0x1a82d0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a82cc) {
            ctx->pc = 0x1A843Cu;
            goto label_1a843c;
        }
    }
    ctx->pc = 0x1A82D4u;
label_1a82d4:
    // 0x1a82d4: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a82d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a82d8: 0x8c220a60  lw          $v0, 0xA60($at)
    ctx->pc = 0x1a82d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a82dc: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1a82dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1a82e0: 0x28420200  slti        $v0, $v0, 0x200
    ctx->pc = 0x1a82e0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)512) ? 1 : 0);
    // 0x1a82e4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A82E4u;
    {
        const bool branch_taken_0x1a82e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A82E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A82E4u;
            // 0x1a82e8: 0x3c03002b  lui         $v1, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a82e4) {
            ctx->pc = 0x1A82F4u;
            goto label_1a82f4;
        }
    }
    ctx->pc = 0x1A82ECu;
    // 0x1a82ec: 0x10000053  b           . + 4 + (0x53 << 2)
    ctx->pc = 0x1A82ECu;
    {
        const bool branch_taken_0x1a82ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A82F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A82ECu;
            // 0x1a82f0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a82ec) {
            ctx->pc = 0x1A843Cu;
            goto label_1a843c;
        }
    }
    ctx->pc = 0x1A82F4u;
label_1a82f4:
    // 0x1a82f4: 0x240c0018  addiu       $t4, $zero, 0x18
    ctx->pc = 0x1a82f4u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1a82f8: 0x240b0004  addiu       $t3, $zero, 0x4
    ctx->pc = 0x1a82f8u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1a82fc: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1A82FCu;
    {
        const bool branch_taken_0x1a82fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A8300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A82FCu;
            // 0x1a8300: 0x24630cc0  addiu       $v1, $v1, 0xCC0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3264));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a82fc) {
            ctx->pc = 0x1A8334u;
            goto label_1a8334;
        }
    }
    ctx->pc = 0x1A8304u;
label_1a8304:
    // 0x1a8304: 0x1845006  srlv        $t2, $a0, $t4
    ctx->pc = 0x1a8304u;
    SET_GPR_S32(ctx, 10, (int32_t)SRL32(GPR_U32(ctx, 4), GPR_U32(ctx, 12) & 0x1F));
    // 0x1a8308: 0x8c220a60  lw          $v0, 0xA60($at)
    ctx->pc = 0x1a8308u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a830c: 0x258cfff8  addiu       $t4, $t4, -0x8
    ctx->pc = 0x1a830cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 4294967288));
    // 0x1a8310: 0x256bffff  addiu       $t3, $t3, -0x1
    ctx->pc = 0x1a8310u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 4294967295));
    // 0x1a8314: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x1a8314u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1a8318: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1a8318u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a831c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a831cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8320: 0xa04a0000  sb          $t2, 0x0($v0)
    ctx->pc = 0x1a8320u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 10));
    // 0x1a8324: 0x8c220a60  lw          $v0, 0xA60($at)
    ctx->pc = 0x1a8324u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a8328: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1a8328u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a832c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a832cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8330: 0xac220a60  sw          $v0, 0xA60($at)
    ctx->pc = 0x1a8330u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2656), GPR_U32(ctx, 2));
label_1a8334:
    // 0x1a8334: 0x19600003  blez        $t3, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A8334u;
    {
        const bool branch_taken_0x1a8334 = (GPR_S64(ctx, 11) <= 0);
        ctx->pc = 0x1A8338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8334u;
            // 0x1a8338: 0xa0102d  daddu       $v0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8334) {
            ctx->pc = 0x1A8344u;
            goto label_1a8344;
        }
    }
    ctx->pc = 0x1A833Cu;
    // 0x1a833c: 0x1ca0fff1  bgtz        $a1, . + 4 + (-0xF << 2)
    ctx->pc = 0x1A833Cu;
    {
        const bool branch_taken_0x1a833c = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x1A8340u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A833Cu;
            // 0x1a8340: 0x3c01002b  lui         $at, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a833c) {
            ctx->pc = 0x1A8304u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a8304;
        }
    }
    ctx->pc = 0x1A8344u;
label_1a8344:
    // 0x1a8344: 0x1840000c  blez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1A8344u;
    {
        const bool branch_taken_0x1a8344 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1A8348u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8344u;
            // 0x1a8348: 0x2445ffff  addiu       $a1, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8344) {
            ctx->pc = 0x1A8378u;
            goto label_1a8378;
        }
    }
    ctx->pc = 0x1A834Cu;
    // 0x1a834c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a834cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8350: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a8350u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a8354: 0x8c230a60  lw          $v1, 0xA60($at)
    ctx->pc = 0x1a8354u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a8358: 0x24420cc0  addiu       $v0, $v0, 0xCC0
    ctx->pc = 0x1a8358u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 3264));
    // 0x1a835c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1a835cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a8360: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a8360u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8364: 0xa0460000  sb          $a2, 0x0($v0)
    ctx->pc = 0x1a8364u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 6));
    // 0x1a8368: 0x8c220a60  lw          $v0, 0xA60($at)
    ctx->pc = 0x1a8368u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a836c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1a836cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a8370: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a8370u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8374: 0xac220a60  sw          $v0, 0xA60($at)
    ctx->pc = 0x1a8374u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2656), GPR_U32(ctx, 2));
label_1a8378:
    // 0x1a8378: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1a8378u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a837c: 0x1840000c  blez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1A837Cu;
    {
        const bool branch_taken_0x1a837c = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1A8380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A837Cu;
            // 0x1a8380: 0x2445ffff  addiu       $a1, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a837c) {
            ctx->pc = 0x1A83B0u;
            goto label_1a83b0;
        }
    }
    ctx->pc = 0x1A8384u;
    // 0x1a8384: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a8384u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8388: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a8388u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a838c: 0x8c230a60  lw          $v1, 0xA60($at)
    ctx->pc = 0x1a838cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a8390: 0x24420cc0  addiu       $v0, $v0, 0xCC0
    ctx->pc = 0x1a8390u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 3264));
    // 0x1a8394: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1a8394u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a8398: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a8398u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a839c: 0xa0470000  sb          $a3, 0x0($v0)
    ctx->pc = 0x1a839cu;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 7));
    // 0x1a83a0: 0x8c220a60  lw          $v0, 0xA60($at)
    ctx->pc = 0x1a83a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a83a4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1a83a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a83a8: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a83a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a83ac: 0xac220a60  sw          $v0, 0xA60($at)
    ctx->pc = 0x1a83acu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2656), GPR_U32(ctx, 2));
label_1a83b0:
    // 0x1a83b0: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1a83b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a83b4: 0x1840000c  blez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1A83B4u;
    {
        const bool branch_taken_0x1a83b4 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1A83B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A83B4u;
            // 0x1a83b8: 0x2445ffff  addiu       $a1, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a83b4) {
            ctx->pc = 0x1A83E8u;
            goto label_1a83e8;
        }
    }
    ctx->pc = 0x1A83BCu;
    // 0x1a83bc: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a83bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a83c0: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a83c0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a83c4: 0x8c230a60  lw          $v1, 0xA60($at)
    ctx->pc = 0x1a83c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a83c8: 0x24420cc0  addiu       $v0, $v0, 0xCC0
    ctx->pc = 0x1a83c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 3264));
    // 0x1a83cc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1a83ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a83d0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a83d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a83d4: 0xa0480000  sb          $t0, 0x0($v0)
    ctx->pc = 0x1a83d4u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 8));
    // 0x1a83d8: 0x8c220a60  lw          $v0, 0xA60($at)
    ctx->pc = 0x1a83d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a83dc: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1a83dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a83e0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a83e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a83e4: 0xac220a60  sw          $v0, 0xA60($at)
    ctx->pc = 0x1a83e4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2656), GPR_U32(ctx, 2));
label_1a83e8:
    // 0x1a83e8: 0x18a0000c  blez        $a1, . + 4 + (0xC << 2)
    ctx->pc = 0x1A83E8u;
    {
        const bool branch_taken_0x1a83e8 = (GPR_S64(ctx, 5) <= 0);
        if (branch_taken_0x1a83e8) {
            ctx->pc = 0x1A841Cu;
            goto label_1a841c;
        }
    }
    ctx->pc = 0x1A83F0u;
    // 0x1a83f0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a83f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a83f4: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a83f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a83f8: 0x8c230a60  lw          $v1, 0xA60($at)
    ctx->pc = 0x1a83f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a83fc: 0x24420cc0  addiu       $v0, $v0, 0xCC0
    ctx->pc = 0x1a83fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 3264));
    // 0x1a8400: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1a8400u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a8404: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a8404u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8408: 0xa0490000  sb          $t1, 0x0($v0)
    ctx->pc = 0x1a8408u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 9));
    // 0x1a840c: 0x8c220a60  lw          $v0, 0xA60($at)
    ctx->pc = 0x1a840cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a8410: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1a8410u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a8414: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a8414u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8418: 0xac220a60  sw          $v0, 0xA60($at)
    ctx->pc = 0x1a8418u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2656), GPR_U32(ctx, 2));
label_1a841c:
    // 0x1a841c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a841cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8420: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a8420u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a8424: 0x8c240a60  lw          $a0, 0xA60($at)
    ctx->pc = 0x1a8424u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2656)));
    // 0x1a8428: 0x24630cc0  addiu       $v1, $v1, 0xCC0
    ctx->pc = 0x1a8428u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3264));
    // 0x1a842c: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x1a842cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1a8430: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a8430u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a8434: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1a8434u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1a8438: 0xa0650000  sb          $a1, 0x0($v1)
    ctx->pc = 0x1a8438u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
label_1a843c:
    // 0x1a843c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a843cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a8440: 0x3e00008  jr          $ra
    ctx->pc = 0x1A8440u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A8444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8440u;
            // 0x1a8444: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A82CCu: goto label_1a82cc;
            case 0x1A82D4u: goto label_1a82d4;
            case 0x1A82F4u: goto label_1a82f4;
            case 0x1A8304u: goto label_1a8304;
            case 0x1A8334u: goto label_1a8334;
            case 0x1A8344u: goto label_1a8344;
            case 0x1A8378u: goto label_1a8378;
            case 0x1A83B0u: goto label_1a83b0;
            case 0x1A83E8u: goto label_1a83e8;
            case 0x1A841Cu: goto label_1a841c;
            case 0x1A843Cu: goto label_1a843c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A8448u;
    // 0x1a8448: 0x0  nop
    ctx->pc = 0x1a8448u;
    // NOP
    // 0x1a844c: 0x0  nop
    ctx->pc = 0x1a844cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
