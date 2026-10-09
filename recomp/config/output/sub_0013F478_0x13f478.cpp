#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F478
// Address: 0x13f478 - 0x13f7f8
void sub_0013F478_0x13f478(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F478_0x13f478");
#endif

    switch (ctx->pc) {
        case 0x13f4c0u: goto label_13f4c0;
        case 0x13f4fcu: goto label_13f4fc;
        case 0x13f570u: goto label_13f570;
        case 0x13f5ccu: goto label_13f5cc;
        case 0x13f5f8u: goto label_13f5f8;
        case 0x13f664u: goto label_13f664;
        case 0x13f6d0u: goto label_13f6d0;
        case 0x13f6f0u: goto label_13f6f0;
        case 0x13f754u: goto label_13f754;
        case 0x13f794u: goto label_13f794;
        case 0x13f79cu: goto label_13f79c;
        default: break;
    }

    ctx->pc = 0x13f478u;

    // 0x13f478: 0x8c820018  lw          $v0, 0x18($a0)
    ctx->pc = 0x13f478u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x13f47c: 0xac800010  sw          $zero, 0x10($a0)
    ctx->pc = 0x13f47cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 0));
    // 0x13f480: 0x3e00008  jr          $ra
    ctx->pc = 0x13F480u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F484u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F480u;
            // 0x13f484: 0xac82000c  sw          $v0, 0xC($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F4A0u: goto label_13f4a0;
            case 0x13F4C0u: goto label_13f4c0;
            case 0x13F4C4u: goto label_13f4c4;
            case 0x13F4FCu: goto label_13f4fc;
            case 0x13F510u: goto label_13f510;
            case 0x13F558u: goto label_13f558;
            case 0x13F570u: goto label_13f570;
            case 0x13F5CCu: goto label_13f5cc;
            case 0x13F5F8u: goto label_13f5f8;
            case 0x13F5FCu: goto label_13f5fc;
            case 0x13F610u: goto label_13f610;
            case 0x13F614u: goto label_13f614;
            case 0x13F664u: goto label_13f664;
            case 0x13F6B8u: goto label_13f6b8;
            case 0x13F6D0u: goto label_13f6d0;
            case 0x13F6D8u: goto label_13f6d8;
            case 0x13F6F0u: goto label_13f6f0;
            case 0x13F6F4u: goto label_13f6f4;
            case 0x13F708u: goto label_13f708;
            case 0x13F70Cu: goto label_13f70c;
            case 0x13F754u: goto label_13f754;
            case 0x13F780u: goto label_13f780;
            case 0x13F794u: goto label_13f794;
            case 0x13F79Cu: goto label_13f79c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F488u;
    // 0x13f488: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f488u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f48c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13f48cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13f490: 0x14a20003  bne         $a1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x13F490u;
    {
        const bool branch_taken_0x13f490 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x13F494u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F490u;
            // 0x13f494: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f490) {
            ctx->pc = 0x13F4A0u;
            goto label_13f4a0;
        }
    }
    ctx->pc = 0x13F498u;
    // 0x13f498: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x13F498u;
    {
        const bool branch_taken_0x13f498 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F49Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F498u;
            // 0x13f49c: 0x8c82000c  lw          $v0, 0xC($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f498) {
            ctx->pc = 0x13F4C4u;
            goto label_13f4c4;
        }
    }
    ctx->pc = 0x13F4A0u;
label_13f4a0:
    // 0x13f4a0: 0x10a00008  beqz        $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x13F4A0u;
    {
        const bool branch_taken_0x13f4a0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F4A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F4A0u;
            // 0x13f4a4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f4a0) {
            ctx->pc = 0x13F4C4u;
            goto label_13f4c4;
        }
    }
    ctx->pc = 0x13F4A8u;
    // 0x13f4a8: 0x8c82001c  lw          $v0, 0x1C($a0)
    ctx->pc = 0x13f4a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x13f4ac: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x13F4ACu;
    {
        const bool branch_taken_0x13f4ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13f4ac) {
            ctx->pc = 0x13F4B0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13F4ACu;
            // 0x13f4b0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13F4C4u;
            goto label_13f4c4;
        }
    }
    ctx->pc = 0x13F4B4u;
    // 0x13f4b4: 0x8c840020  lw          $a0, 0x20($a0)
    ctx->pc = 0x13f4b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x13f4b8: 0x40f809  jalr        $v0
    ctx->pc = 0x13F4B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13F4C0u);
        ctx->pc = 0x13F4BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F4B8u;
            // 0x13f4bc: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13F4C0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F4A0u: goto label_13f4a0;
            case 0x13F4C0u: goto label_13f4c0;
            case 0x13F4C4u: goto label_13f4c4;
            case 0x13F4FCu: goto label_13f4fc;
            case 0x13F510u: goto label_13f510;
            case 0x13F558u: goto label_13f558;
            case 0x13F570u: goto label_13f570;
            case 0x13F5CCu: goto label_13f5cc;
            case 0x13F5F8u: goto label_13f5f8;
            case 0x13F5FCu: goto label_13f5fc;
            case 0x13F610u: goto label_13f610;
            case 0x13F614u: goto label_13f614;
            case 0x13F664u: goto label_13f664;
            case 0x13F6B8u: goto label_13f6b8;
            case 0x13F6D0u: goto label_13f6d0;
            case 0x13F6D8u: goto label_13f6d8;
            case 0x13F6F0u: goto label_13f6f0;
            case 0x13F6F4u: goto label_13f6f4;
            case 0x13F708u: goto label_13f708;
            case 0x13F70Cu: goto label_13f70c;
            case 0x13F754u: goto label_13f754;
            case 0x13F780u: goto label_13f780;
            case 0x13F794u: goto label_13f794;
            case 0x13F79Cu: goto label_13f79c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13F4C0u; }
            if (ctx->pc != 0x13F4C0u) { return; }
        }
        }
    }
    ctx->pc = 0x13F4C0u;
label_13f4c0:
    // 0x13f4c0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x13f4c0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_13f4c4:
    // 0x13f4c4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f4c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f4c8: 0x3e00008  jr          $ra
    ctx->pc = 0x13F4C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F4CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F4C8u;
            // 0x13f4cc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F4A0u: goto label_13f4a0;
            case 0x13F4C0u: goto label_13f4c0;
            case 0x13F4C4u: goto label_13f4c4;
            case 0x13F4FCu: goto label_13f4fc;
            case 0x13F510u: goto label_13f510;
            case 0x13F558u: goto label_13f558;
            case 0x13F570u: goto label_13f570;
            case 0x13F5CCu: goto label_13f5cc;
            case 0x13F5F8u: goto label_13f5f8;
            case 0x13F5FCu: goto label_13f5fc;
            case 0x13F610u: goto label_13f610;
            case 0x13F614u: goto label_13f614;
            case 0x13F664u: goto label_13f664;
            case 0x13F6B8u: goto label_13f6b8;
            case 0x13F6D0u: goto label_13f6d0;
            case 0x13F6D8u: goto label_13f6d8;
            case 0x13F6F0u: goto label_13f6f0;
            case 0x13F6F4u: goto label_13f6f4;
            case 0x13F708u: goto label_13f708;
            case 0x13F70Cu: goto label_13f70c;
            case 0x13F754u: goto label_13f754;
            case 0x13F780u: goto label_13f780;
            case 0x13F794u: goto label_13f794;
            case 0x13F79Cu: goto label_13f79c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F4D0u;
    // 0x13f4d0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x13f4d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13f4d4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13f4d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13f4d8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x13f4d8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f4dc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13f4dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13f4e0: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x13f4e0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f4e4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13f4e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13f4e8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x13f4e8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f4ec: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13f4ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13f4f0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x13f4f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x13f4f4: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x13F4F4u;
    SET_GPR_U32(ctx, 31, 0x13F4FCu);
    ctx->pc = 0x13F4F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F4F4u;
            // 0x13f4f8: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F4FCu; }
        if (ctx->pc != 0x13F4FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F4FCu; }
        if (ctx->pc != 0x13F4FCu) { return; }
    }
    ctx->pc = 0x13F4FCu;
label_13f4fc:
    // 0x13f4fc: 0x16400004  bnez        $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x13F4FCu;
    {
        const bool branch_taken_0x13f4fc = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x13F500u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F4FCu;
            // 0x13f500: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f4fc) {
            ctx->pc = 0x13F510u;
            goto label_13f510;
        }
    }
    ctx->pc = 0x13F504u;
    // 0x13f504: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x13f504u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x13f508: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x13F508u;
    {
        const bool branch_taken_0x13f508 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F50Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F508u;
            // 0x13f50c: 0xae000004  sw          $zero, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f508) {
            ctx->pc = 0x13F570u;
            goto label_13f570;
        }
    }
    ctx->pc = 0x13F510u;
label_13f510:
    // 0x13f510: 0x56420011  bnel        $s2, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x13F510u;
    {
        const bool branch_taken_0x13f510 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        if (branch_taken_0x13f510) {
            ctx->pc = 0x13F514u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13F510u;
            // 0x13f514: 0x8e22001c  lw          $v0, 0x1C($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13F558u;
            goto label_13f558;
        }
    }
    ctx->pc = 0x13F518u;
    // 0x13f518: 0x8e22000c  lw          $v0, 0xC($s1)
    ctx->pc = 0x13f518u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x13f51c: 0x8e250014  lw          $a1, 0x14($s1)
    ctx->pc = 0x13f51cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x13f520: 0x53182a  slt         $v1, $v0, $s3
    ctx->pc = 0x13f520u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x13f524: 0x263100a  movz        $v0, $s3, $v1
    ctx->pc = 0x13f524u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 19));
    // 0x13f528: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x13f528u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x13f52c: 0x8e240010  lw          $a0, 0x10($s1)
    ctx->pc = 0x13f52cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x13f530: 0x8e23000c  lw          $v1, 0xC($s1)
    ctx->pc = 0x13f530u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x13f534: 0x821021  addu        $v0, $a0, $v0
    ctx->pc = 0x13f534u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x13f538: 0xa42821  addu        $a1, $a1, $a0
    ctx->pc = 0x13f538u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x13f53c: 0xae220010  sw          $v0, 0x10($s1)
    ctx->pc = 0x13f53cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 2));
    // 0x13f540: 0xae050000  sw          $a1, 0x0($s0)
    ctx->pc = 0x13f540u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 5));
    // 0x13f544: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x13f544u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x13f548: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x13f548u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13f54c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x13F54Cu;
    {
        const bool branch_taken_0x13f54c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F54Cu;
            // 0x13f550: 0xae23000c  sw          $v1, 0xC($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f54c) {
            ctx->pc = 0x13F570u;
            goto label_13f570;
        }
    }
    ctx->pc = 0x13F554u;
    // 0x13f554: 0x0  nop
    ctx->pc = 0x13f554u;
    // NOP
label_13f558:
    // 0x13f558: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x13f558u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x13f55c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13F55Cu;
    {
        const bool branch_taken_0x13f55c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F560u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F55Cu;
            // 0x13f560: 0xae000004  sw          $zero, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f55c) {
            ctx->pc = 0x13F570u;
            goto label_13f570;
        }
    }
    ctx->pc = 0x13F564u;
    // 0x13f564: 0x8e240020  lw          $a0, 0x20($s1)
    ctx->pc = 0x13f564u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x13f568: 0x40f809  jalr        $v0
    ctx->pc = 0x13F568u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13F570u);
        ctx->pc = 0x13F56Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F568u;
            // 0x13f56c: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13F570u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F4A0u: goto label_13f4a0;
            case 0x13F4C0u: goto label_13f4c0;
            case 0x13F4C4u: goto label_13f4c4;
            case 0x13F4FCu: goto label_13f4fc;
            case 0x13F510u: goto label_13f510;
            case 0x13F558u: goto label_13f558;
            case 0x13F570u: goto label_13f570;
            case 0x13F5CCu: goto label_13f5cc;
            case 0x13F5F8u: goto label_13f5f8;
            case 0x13F5FCu: goto label_13f5fc;
            case 0x13F610u: goto label_13f610;
            case 0x13F614u: goto label_13f614;
            case 0x13F664u: goto label_13f664;
            case 0x13F6B8u: goto label_13f6b8;
            case 0x13F6D0u: goto label_13f6d0;
            case 0x13F6D8u: goto label_13f6d8;
            case 0x13F6F0u: goto label_13f6f0;
            case 0x13F6F4u: goto label_13f6f4;
            case 0x13F708u: goto label_13f708;
            case 0x13F70Cu: goto label_13f70c;
            case 0x13F754u: goto label_13f754;
            case 0x13F780u: goto label_13f780;
            case 0x13F794u: goto label_13f794;
            case 0x13F79Cu: goto label_13f79c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13F570u; }
            if (ctx->pc != 0x13F570u) { return; }
        }
        }
    }
    ctx->pc = 0x13F570u;
label_13f570:
    // 0x13f570: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13f570u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f574: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13f574u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13f578: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13f578u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13f57c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13f57cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13f580: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x13f580u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13f584: 0x804fc9c  j           func_13F270
    ctx->pc = 0x13F584u;
    ctx->pc = 0x13F588u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F584u;
            // 0x13f588: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13F58Cu;
    // 0x13f58c: 0x0  nop
    ctx->pc = 0x13f58cu;
    // NOP
    // 0x13f590: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13f590u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13f594: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13f594u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13f598: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x13f598u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f59c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13f59cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13f5a0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x13f5a0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f5a4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13f5a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13f5a8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x13f5a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x13f5ac: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x13f5acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x13f5b0: 0x18400017  blez        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x13F5B0u;
    {
        const bool branch_taken_0x13f5b0 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x13F5B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F5B0u;
            // 0x13f5b4: 0x80902d  daddu       $s2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f5b0) {
            ctx->pc = 0x13F610u;
            goto label_13f610;
        }
    }
    ctx->pc = 0x13F5B8u;
    // 0x13f5b8: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x13f5b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13f5bc: 0x50400015  beql        $v0, $zero, . + 4 + (0x15 << 2)
    ctx->pc = 0x13F5BCu;
    {
        const bool branch_taken_0x13f5bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13f5bc) {
            ctx->pc = 0x13F5C0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13F5BCu;
            // 0x13f5c0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13F614u;
            goto label_13f614;
        }
    }
    ctx->pc = 0x13F5C4u;
    // 0x13f5c4: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x13F5C4u;
    SET_GPR_U32(ctx, 31, 0x13F5CCu);
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F5CCu; }
        if (ctx->pc != 0x13F5CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F5CCu; }
        if (ctx->pc != 0x13F5CCu) { return; }
    }
    ctx->pc = 0x13F5CCu;
label_13f5cc:
    // 0x13f5cc: 0x1220000a  beqz        $s1, . + 4 + (0xA << 2)
    ctx->pc = 0x13F5CCu;
    {
        const bool branch_taken_0x13f5cc = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F5D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F5CCu;
            // 0x13f5d0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f5cc) {
            ctx->pc = 0x13F5F8u;
            goto label_13f5f8;
        }
    }
    ctx->pc = 0x13F5D4u;
    // 0x13f5d4: 0x52220009  beql        $s1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x13F5D4u;
    {
        const bool branch_taken_0x13f5d4 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        if (branch_taken_0x13f5d4) {
            ctx->pc = 0x13F5D8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13F5D4u;
            // 0x13f5d8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13F5FCu;
            goto label_13f5fc;
        }
    }
    ctx->pc = 0x13F5DCu;
    // 0x13f5dc: 0x8e42001c  lw          $v0, 0x1C($s2)
    ctx->pc = 0x13f5dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 28)));
    // 0x13f5e0: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x13f5e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x13f5e4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13F5E4u;
    {
        const bool branch_taken_0x13f5e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F5E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F5E4u;
            // 0x13f5e8: 0xae000004  sw          $zero, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f5e4) {
            ctx->pc = 0x13F5F8u;
            goto label_13f5f8;
        }
    }
    ctx->pc = 0x13F5ECu;
    // 0x13f5ec: 0x8e440020  lw          $a0, 0x20($s2)
    ctx->pc = 0x13f5ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 32)));
    // 0x13f5f0: 0x40f809  jalr        $v0
    ctx->pc = 0x13F5F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13F5F8u);
        ctx->pc = 0x13F5F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F5F0u;
            // 0x13f5f4: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13F5F8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F4A0u: goto label_13f4a0;
            case 0x13F4C0u: goto label_13f4c0;
            case 0x13F4C4u: goto label_13f4c4;
            case 0x13F4FCu: goto label_13f4fc;
            case 0x13F510u: goto label_13f510;
            case 0x13F558u: goto label_13f558;
            case 0x13F570u: goto label_13f570;
            case 0x13F5CCu: goto label_13f5cc;
            case 0x13F5F8u: goto label_13f5f8;
            case 0x13F5FCu: goto label_13f5fc;
            case 0x13F610u: goto label_13f610;
            case 0x13F614u: goto label_13f614;
            case 0x13F664u: goto label_13f664;
            case 0x13F6B8u: goto label_13f6b8;
            case 0x13F6D0u: goto label_13f6d0;
            case 0x13F6D8u: goto label_13f6d8;
            case 0x13F6F0u: goto label_13f6f0;
            case 0x13F6F4u: goto label_13f6f4;
            case 0x13F708u: goto label_13f708;
            case 0x13F70Cu: goto label_13f70c;
            case 0x13F754u: goto label_13f754;
            case 0x13F780u: goto label_13f780;
            case 0x13F794u: goto label_13f794;
            case 0x13F79Cu: goto label_13f79c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13F5F8u; }
            if (ctx->pc != 0x13F5F8u) { return; }
        }
        }
    }
    ctx->pc = 0x13F5F8u;
label_13f5f8:
    // 0x13f5f8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13f5f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13f5fc:
    // 0x13f5fc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13f5fcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13f600: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13f600u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13f604: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13f604u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13f608: 0x804fc9c  j           func_13F270
    ctx->pc = 0x13F608u;
    ctx->pc = 0x13F60Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F608u;
            // 0x13f60c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13F610u;
label_13f610:
    // 0x13f610: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13f610u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13f614:
    // 0x13f614: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13f614u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13f618: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13f618u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13f61c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13f61cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13f620: 0x3e00008  jr          $ra
    ctx->pc = 0x13F620u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F620u;
            // 0x13f624: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F4A0u: goto label_13f4a0;
            case 0x13F4C0u: goto label_13f4c0;
            case 0x13F4C4u: goto label_13f4c4;
            case 0x13F4FCu: goto label_13f4fc;
            case 0x13F510u: goto label_13f510;
            case 0x13F558u: goto label_13f558;
            case 0x13F570u: goto label_13f570;
            case 0x13F5CCu: goto label_13f5cc;
            case 0x13F5F8u: goto label_13f5f8;
            case 0x13F5FCu: goto label_13f5fc;
            case 0x13F610u: goto label_13f610;
            case 0x13F614u: goto label_13f614;
            case 0x13F664u: goto label_13f664;
            case 0x13F6B8u: goto label_13f6b8;
            case 0x13F6D0u: goto label_13f6d0;
            case 0x13F6D8u: goto label_13f6d8;
            case 0x13F6F0u: goto label_13f6f0;
            case 0x13F6F4u: goto label_13f6f4;
            case 0x13F708u: goto label_13f708;
            case 0x13F70Cu: goto label_13f70c;
            case 0x13F754u: goto label_13f754;
            case 0x13F780u: goto label_13f780;
            case 0x13F794u: goto label_13f794;
            case 0x13F79Cu: goto label_13f79c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F628u;
    // 0x13f628: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13f628u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13f62c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13f62cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13f630: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13f630u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f634: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13f634u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13f638: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x13f638u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f63c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13f63cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13f640: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x13f640u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x13f644: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x13f644u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13f648: 0x1840002f  blez        $v0, . + 4 + (0x2F << 2)
    ctx->pc = 0x13F648u;
    {
        const bool branch_taken_0x13f648 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x13F64Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F648u;
            // 0x13f64c: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f648) {
            ctx->pc = 0x13F708u;
            goto label_13f708;
        }
    }
    ctx->pc = 0x13F650u;
    // 0x13f650: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x13f650u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13f654: 0x5040002d  beql        $v0, $zero, . + 4 + (0x2D << 2)
    ctx->pc = 0x13F654u;
    {
        const bool branch_taken_0x13f654 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13f654) {
            ctx->pc = 0x13F658u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13F654u;
            // 0x13f658: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13F70Cu;
            goto label_13f70c;
        }
    }
    ctx->pc = 0x13F65Cu;
    // 0x13f65c: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x13F65Cu;
    SET_GPR_U32(ctx, 31, 0x13F664u);
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F664u; }
        if (ctx->pc != 0x13F664u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F664u; }
        if (ctx->pc != 0x13F664u) { return; }
    }
    ctx->pc = 0x13F664u;
label_13f664:
    // 0x13f664: 0x12400014  beqz        $s2, . + 4 + (0x14 << 2)
    ctx->pc = 0x13F664u;
    {
        const bool branch_taken_0x13f664 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F668u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F664u;
            // 0x13f668: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f664) {
            ctx->pc = 0x13F6B8u;
            goto label_13f6b8;
        }
    }
    ctx->pc = 0x13F66Cu;
    // 0x13f66c: 0x5642001a  bnel        $s2, $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x13F66Cu;
    {
        const bool branch_taken_0x13f66c = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        if (branch_taken_0x13f66c) {
            ctx->pc = 0x13F670u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13F66Cu;
            // 0x13f670: 0x8e02001c  lw          $v0, 0x1C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13F6D8u;
            goto label_13f6d8;
        }
    }
    ctx->pc = 0x13F674u;
    // 0x13f674: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x13f674u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13f678: 0x8e040010  lw          $a0, 0x10($s0)
    ctx->pc = 0x13f678u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x13f67c: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x13f67cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x13f680: 0x822023  subu        $a0, $a0, $v0
    ctx->pc = 0x13f680u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x13f684: 0x8e070018  lw          $a3, 0x18($s0)
    ctx->pc = 0x13f684u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x13f688: 0x28820000  slti        $v0, $a0, 0x0
    ctx->pc = 0x13f688u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x13f68c: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x13f68cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x13f690: 0x2200b  movn        $a0, $zero, $v0
    ctx->pc = 0x13f690u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 0));
    // 0x13f694: 0x8e260000  lw          $a2, 0x0($s1)
    ctx->pc = 0x13f694u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13f698: 0xae040010  sw          $a0, 0x10($s0)
    ctx->pc = 0x13f698u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 4));
    // 0x13f69c: 0xc33023  subu        $a2, $a2, $v1
    ctx->pc = 0x13f69cu;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x13f6a0: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x13f6a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13f6a4: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x13f6a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x13f6a8: 0xe5182a  slt         $v1, $a3, $a1
    ctx->pc = 0x13f6a8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x13f6ac: 0xe3280b  movn        $a1, $a3, $v1
    ctx->pc = 0x13f6acu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 7));
    // 0x13f6b0: 0x1086000f  beq         $a0, $a2, . + 4 + (0xF << 2)
    ctx->pc = 0x13F6B0u;
    {
        const bool branch_taken_0x13f6b0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 6));
        ctx->pc = 0x13F6B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F6B0u;
            // 0x13f6b4: 0xae05000c  sw          $a1, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f6b0) {
            ctx->pc = 0x13F6F0u;
            goto label_13f6f0;
        }
    }
    ctx->pc = 0x13F6B8u;
label_13f6b8:
    // 0x13f6b8: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x13f6b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x13f6bc: 0x5040000d  beql        $v0, $zero, . + 4 + (0xD << 2)
    ctx->pc = 0x13F6BCu;
    {
        const bool branch_taken_0x13f6bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13f6bc) {
            ctx->pc = 0x13F6C0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13F6BCu;
            // 0x13f6c0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13F6F4u;
            goto label_13f6f4;
        }
    }
    ctx->pc = 0x13F6C4u;
    // 0x13f6c4: 0x8e040020  lw          $a0, 0x20($s0)
    ctx->pc = 0x13f6c4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13f6c8: 0x40f809  jalr        $v0
    ctx->pc = 0x13F6C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13F6D0u);
        ctx->pc = 0x13F6CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F6C8u;
            // 0x13f6cc: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13F6D0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F4A0u: goto label_13f4a0;
            case 0x13F4C0u: goto label_13f4c0;
            case 0x13F4C4u: goto label_13f4c4;
            case 0x13F4FCu: goto label_13f4fc;
            case 0x13F510u: goto label_13f510;
            case 0x13F558u: goto label_13f558;
            case 0x13F570u: goto label_13f570;
            case 0x13F5CCu: goto label_13f5cc;
            case 0x13F5F8u: goto label_13f5f8;
            case 0x13F5FCu: goto label_13f5fc;
            case 0x13F610u: goto label_13f610;
            case 0x13F614u: goto label_13f614;
            case 0x13F664u: goto label_13f664;
            case 0x13F6B8u: goto label_13f6b8;
            case 0x13F6D0u: goto label_13f6d0;
            case 0x13F6D8u: goto label_13f6d8;
            case 0x13F6F0u: goto label_13f6f0;
            case 0x13F6F4u: goto label_13f6f4;
            case 0x13F708u: goto label_13f708;
            case 0x13F70Cu: goto label_13f70c;
            case 0x13F754u: goto label_13f754;
            case 0x13F780u: goto label_13f780;
            case 0x13F794u: goto label_13f794;
            case 0x13F79Cu: goto label_13f79c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13F6D0u; }
            if (ctx->pc != 0x13F6D0u) { return; }
        }
        }
    }
    ctx->pc = 0x13F6D0u;
label_13f6d0:
    // 0x13f6d0: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x13F6D0u;
    {
        const bool branch_taken_0x13f6d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F6D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F6D0u;
            // 0x13f6d4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f6d0) {
            ctx->pc = 0x13F6F4u;
            goto label_13f6f4;
        }
    }
    ctx->pc = 0x13F6D8u;
label_13f6d8:
    // 0x13f6d8: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x13f6d8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x13f6dc: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13F6DCu;
    {
        const bool branch_taken_0x13f6dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F6E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F6DCu;
            // 0x13f6e0: 0xae200004  sw          $zero, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f6dc) {
            ctx->pc = 0x13F6F0u;
            goto label_13f6f0;
        }
    }
    ctx->pc = 0x13F6E4u;
    // 0x13f6e4: 0x8e040020  lw          $a0, 0x20($s0)
    ctx->pc = 0x13f6e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13f6e8: 0x40f809  jalr        $v0
    ctx->pc = 0x13F6E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13F6F0u);
        ctx->pc = 0x13F6ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F6E8u;
            // 0x13f6ec: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13F6F0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F4A0u: goto label_13f4a0;
            case 0x13F4C0u: goto label_13f4c0;
            case 0x13F4C4u: goto label_13f4c4;
            case 0x13F4FCu: goto label_13f4fc;
            case 0x13F510u: goto label_13f510;
            case 0x13F558u: goto label_13f558;
            case 0x13F570u: goto label_13f570;
            case 0x13F5CCu: goto label_13f5cc;
            case 0x13F5F8u: goto label_13f5f8;
            case 0x13F5FCu: goto label_13f5fc;
            case 0x13F610u: goto label_13f610;
            case 0x13F614u: goto label_13f614;
            case 0x13F664u: goto label_13f664;
            case 0x13F6B8u: goto label_13f6b8;
            case 0x13F6D0u: goto label_13f6d0;
            case 0x13F6D8u: goto label_13f6d8;
            case 0x13F6F0u: goto label_13f6f0;
            case 0x13F6F4u: goto label_13f6f4;
            case 0x13F708u: goto label_13f708;
            case 0x13F70Cu: goto label_13f70c;
            case 0x13F754u: goto label_13f754;
            case 0x13F780u: goto label_13f780;
            case 0x13F794u: goto label_13f794;
            case 0x13F79Cu: goto label_13f79c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13F6F0u; }
            if (ctx->pc != 0x13F6F0u) { return; }
        }
        }
    }
    ctx->pc = 0x13F6F0u;
label_13f6f0:
    // 0x13f6f0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13f6f0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13f6f4:
    // 0x13f6f4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13f6f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13f6f8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13f6f8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13f6fc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13f6fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13f700: 0x804fc9c  j           func_13F270
    ctx->pc = 0x13F700u;
    ctx->pc = 0x13F704u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F700u;
            // 0x13f704: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13F708u;
label_13f708:
    // 0x13f708: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13f708u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13f70c:
    // 0x13f70c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13f70cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13f710: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13f710u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13f714: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13f714u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13f718: 0x3e00008  jr          $ra
    ctx->pc = 0x13F718u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F71Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F718u;
            // 0x13f71c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F4A0u: goto label_13f4a0;
            case 0x13F4C0u: goto label_13f4c0;
            case 0x13F4C4u: goto label_13f4c4;
            case 0x13F4FCu: goto label_13f4fc;
            case 0x13F510u: goto label_13f510;
            case 0x13F558u: goto label_13f558;
            case 0x13F570u: goto label_13f570;
            case 0x13F5CCu: goto label_13f5cc;
            case 0x13F5F8u: goto label_13f5f8;
            case 0x13F5FCu: goto label_13f5fc;
            case 0x13F610u: goto label_13f610;
            case 0x13F614u: goto label_13f614;
            case 0x13F664u: goto label_13f664;
            case 0x13F6B8u: goto label_13f6b8;
            case 0x13F6D0u: goto label_13f6d0;
            case 0x13F6D8u: goto label_13f6d8;
            case 0x13F6F0u: goto label_13f6f0;
            case 0x13F6F4u: goto label_13f6f4;
            case 0x13F708u: goto label_13f708;
            case 0x13F70Cu: goto label_13f70c;
            case 0x13F754u: goto label_13f754;
            case 0x13F780u: goto label_13f780;
            case 0x13F794u: goto label_13f794;
            case 0x13F79Cu: goto label_13f79c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F720u;
    // 0x13f720: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x13f720u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13f724: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13f724u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13f728: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x13f728u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f72c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13f72cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13f730: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13f730u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f734: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13f734u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13f738: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x13f738u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f73c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13f73cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13f740: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x13f740u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f744: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x13f744u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x13f748: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x13f748u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x13f74c: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x13F74Cu;
    SET_GPR_U32(ctx, 31, 0x13F754u);
    ctx->pc = 0x13F750u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F74Cu;
            // 0x13f750: 0xe0a02d  daddu       $s4, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F754u; }
        if (ctx->pc != 0x13F754u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F754u; }
        if (ctx->pc != 0x13F754u) { return; }
    }
    ctx->pc = 0x13F754u;
label_13f754:
    // 0x13f754: 0x1260000f  beqz        $s3, . + 4 + (0xF << 2)
    ctx->pc = 0x13F754u;
    {
        const bool branch_taken_0x13f754 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F758u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F754u;
            // 0x13f758: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f754) {
            ctx->pc = 0x13F794u;
            goto label_13f794;
        }
    }
    ctx->pc = 0x13F75Cu;
    // 0x13f75c: 0x56620008  bnel        $s3, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x13F75Cu;
    {
        const bool branch_taken_0x13f75c = (GPR_U64(ctx, 19) != GPR_U64(ctx, 2));
        if (branch_taken_0x13f75c) {
            ctx->pc = 0x13F760u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13F75Cu;
            // 0x13f760: 0x8e02001c  lw          $v0, 0x1C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13F780u;
            goto label_13f780;
        }
    }
    ctx->pc = 0x13F764u;
    // 0x13f764: 0x8e04000c  lw          $a0, 0xC($s0)
    ctx->pc = 0x13f764u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x13f768: 0x92102a  slt         $v0, $a0, $s2
    ctx->pc = 0x13f768u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x13f76c: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x13F76Cu;
    {
        const bool branch_taken_0x13f76c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F770u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F76Cu;
            // 0x13f770: 0x240882d  daddu       $s1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f76c) {
            ctx->pc = 0x13F794u;
            goto label_13f794;
        }
    }
    ctx->pc = 0x13F774u;
    // 0x13f774: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x13F774u;
    {
        const bool branch_taken_0x13f774 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F778u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F774u;
            // 0x13f778: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f774) {
            ctx->pc = 0x13F794u;
            goto label_13f794;
        }
    }
    ctx->pc = 0x13F77Cu;
    // 0x13f77c: 0x0  nop
    ctx->pc = 0x13f77cu;
    // NOP
label_13f780:
    // 0x13f780: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13F780u;
    {
        const bool branch_taken_0x13f780 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F784u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F780u;
            // 0x13f784: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f780) {
            ctx->pc = 0x13F794u;
            goto label_13f794;
        }
    }
    ctx->pc = 0x13F788u;
    // 0x13f788: 0x8e040020  lw          $a0, 0x20($s0)
    ctx->pc = 0x13f788u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13f78c: 0x40f809  jalr        $v0
    ctx->pc = 0x13F78Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13F794u);
        ctx->pc = 0x13F790u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F78Cu;
            // 0x13f790: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13F794u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F4A0u: goto label_13f4a0;
            case 0x13F4C0u: goto label_13f4c0;
            case 0x13F4C4u: goto label_13f4c4;
            case 0x13F4FCu: goto label_13f4fc;
            case 0x13F510u: goto label_13f510;
            case 0x13F558u: goto label_13f558;
            case 0x13F570u: goto label_13f570;
            case 0x13F5CCu: goto label_13f5cc;
            case 0x13F5F8u: goto label_13f5f8;
            case 0x13F5FCu: goto label_13f5fc;
            case 0x13F610u: goto label_13f610;
            case 0x13F614u: goto label_13f614;
            case 0x13F664u: goto label_13f664;
            case 0x13F6B8u: goto label_13f6b8;
            case 0x13F6D0u: goto label_13f6d0;
            case 0x13F6D8u: goto label_13f6d8;
            case 0x13F6F0u: goto label_13f6f0;
            case 0x13F6F4u: goto label_13f6f4;
            case 0x13F708u: goto label_13f708;
            case 0x13F70Cu: goto label_13f70c;
            case 0x13F754u: goto label_13f754;
            case 0x13F780u: goto label_13f780;
            case 0x13F794u: goto label_13f794;
            case 0x13F79Cu: goto label_13f79c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13F794u; }
            if (ctx->pc != 0x13F794u) { return; }
        }
        }
    }
    ctx->pc = 0x13F794u;
label_13f794:
    // 0x13f794: 0xc04fc9c  jal         func_13F270
    ctx->pc = 0x13F794u;
    SET_GPR_U32(ctx, 31, 0x13F79Cu);
    ctx->pc = 0x13F798u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F794u;
            // 0x13f798: 0xae910000  sw          $s1, 0x0($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F79Cu; }
        if (ctx->pc != 0x13F79Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F270_0x13f270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F79Cu; }
        if (ctx->pc != 0x13F79Cu) { return; }
    }
    ctx->pc = 0x13F79Cu;
label_13f79c:
    // 0x13f79c: 0x2321026  xor         $v0, $s1, $s2
    ctx->pc = 0x13f79cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) ^ GPR_U64(ctx, 18));
    // 0x13f7a0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13f7a0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f7a4: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x13f7a4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x13f7a8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13f7a8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13f7ac: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13f7acu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13f7b0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13f7b0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13f7b4: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x13f7b4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13f7b8: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x13f7b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13f7bc: 0x3e00008  jr          $ra
    ctx->pc = 0x13F7BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F7C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F7BCu;
            // 0x13f7c0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F4A0u: goto label_13f4a0;
            case 0x13F4C0u: goto label_13f4c0;
            case 0x13F4C4u: goto label_13f4c4;
            case 0x13F4FCu: goto label_13f4fc;
            case 0x13F510u: goto label_13f510;
            case 0x13F558u: goto label_13f558;
            case 0x13F570u: goto label_13f570;
            case 0x13F5CCu: goto label_13f5cc;
            case 0x13F5F8u: goto label_13f5f8;
            case 0x13F5FCu: goto label_13f5fc;
            case 0x13F610u: goto label_13f610;
            case 0x13F614u: goto label_13f614;
            case 0x13F664u: goto label_13f664;
            case 0x13F6B8u: goto label_13f6b8;
            case 0x13F6D0u: goto label_13f6d0;
            case 0x13F6D8u: goto label_13f6d8;
            case 0x13F6F0u: goto label_13f6f0;
            case 0x13F6F4u: goto label_13f6f4;
            case 0x13F708u: goto label_13f708;
            case 0x13F70Cu: goto label_13f70c;
            case 0x13F754u: goto label_13f754;
            case 0x13F780u: goto label_13f780;
            case 0x13F794u: goto label_13f794;
            case 0x13F79Cu: goto label_13f79c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F7C4u;
    // 0x13f7c4: 0x0  nop
    ctx->pc = 0x13f7c4u;
    // NOP
    // 0x13f7c8: 0x3e00008  jr          $ra
    ctx->pc = 0x13F7C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F7CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F7C8u;
            // 0x13f7cc: 0x8c820014  lw          $v0, 0x14($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F4A0u: goto label_13f4a0;
            case 0x13F4C0u: goto label_13f4c0;
            case 0x13F4C4u: goto label_13f4c4;
            case 0x13F4FCu: goto label_13f4fc;
            case 0x13F510u: goto label_13f510;
            case 0x13F558u: goto label_13f558;
            case 0x13F570u: goto label_13f570;
            case 0x13F5CCu: goto label_13f5cc;
            case 0x13F5F8u: goto label_13f5f8;
            case 0x13F5FCu: goto label_13f5fc;
            case 0x13F610u: goto label_13f610;
            case 0x13F614u: goto label_13f614;
            case 0x13F664u: goto label_13f664;
            case 0x13F6B8u: goto label_13f6b8;
            case 0x13F6D0u: goto label_13f6d0;
            case 0x13F6D8u: goto label_13f6d8;
            case 0x13F6F0u: goto label_13f6f0;
            case 0x13F6F4u: goto label_13f6f4;
            case 0x13F708u: goto label_13f708;
            case 0x13F70Cu: goto label_13f70c;
            case 0x13F754u: goto label_13f754;
            case 0x13F780u: goto label_13f780;
            case 0x13F794u: goto label_13f794;
            case 0x13F79Cu: goto label_13f79c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F7D0u;
    // 0x13f7d0: 0x3e00008  jr          $ra
    ctx->pc = 0x13F7D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F7D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F7D0u;
            // 0x13f7d4: 0x8c820018  lw          $v0, 0x18($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F4A0u: goto label_13f4a0;
            case 0x13F4C0u: goto label_13f4c0;
            case 0x13F4C4u: goto label_13f4c4;
            case 0x13F4FCu: goto label_13f4fc;
            case 0x13F510u: goto label_13f510;
            case 0x13F558u: goto label_13f558;
            case 0x13F570u: goto label_13f570;
            case 0x13F5CCu: goto label_13f5cc;
            case 0x13F5F8u: goto label_13f5f8;
            case 0x13F5FCu: goto label_13f5fc;
            case 0x13F610u: goto label_13f610;
            case 0x13F614u: goto label_13f614;
            case 0x13F664u: goto label_13f664;
            case 0x13F6B8u: goto label_13f6b8;
            case 0x13F6D0u: goto label_13f6d0;
            case 0x13F6D8u: goto label_13f6d8;
            case 0x13F6F0u: goto label_13f6f0;
            case 0x13F6F4u: goto label_13f6f4;
            case 0x13F708u: goto label_13f708;
            case 0x13F70Cu: goto label_13f70c;
            case 0x13F754u: goto label_13f754;
            case 0x13F780u: goto label_13f780;
            case 0x13F794u: goto label_13f794;
            case 0x13F79Cu: goto label_13f79c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F7D8u;
    // 0x13f7d8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f7d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f7dc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13f7dcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13f7e0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13f7e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13f7e4: 0x2484da68  addiu       $a0, $a0, -0x2598
    ctx->pc = 0x13f7e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957672));
    // 0x13f7e8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f7e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f7ec: 0x804fca2  j           func_13F288
    ctx->pc = 0x13F7ECu;
    ctx->pc = 0x13F7F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F7ECu;
            // 0x13f7f0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F288u;
    if (runtime->hasFunction(0x13F288u)) {
        auto targetFn = runtime->lookupFunction(0x13F288u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F288_0x13f288(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13F7F4u;
    // 0x13f7f4: 0x0  nop
    ctx->pc = 0x13f7f4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
