#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017C140
// Address: 0x17c140 - 0x17c530
void sub_0017C140_0x17c140(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017C140_0x17c140");
#endif

    switch (ctx->pc) {
        case 0x17c1a0u: goto label_17c1a0;
        case 0x17c1acu: goto label_17c1ac;
        case 0x17c360u: goto label_17c360;
        case 0x17c3c0u: goto label_17c3c0;
        case 0x17c3d0u: goto label_17c3d0;
        case 0x17c3e4u: goto label_17c3e4;
        case 0x17c3f4u: goto label_17c3f4;
        case 0x17c4a8u: goto label_17c4a8;
        case 0x17c4f8u: goto label_17c4f8;
        case 0x17c508u: goto label_17c508;
        default: break;
    }

    ctx->pc = 0x17c140u;

    // 0x17c140: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17c140u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17c144: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x17c144u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c148: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17c148u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17c14c: 0x24060020  addiu       $a2, $zero, 0x20
    ctx->pc = 0x17c14cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x17c150: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17c150u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c154: 0x805f058  j           func_17C160
    ctx->pc = 0x17C154u;
    ctx->pc = 0x17C158u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C154u;
            // 0x17c158: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C160u;
    goto label_17c160;
    ctx->pc = 0x17C15Cu;
    // 0x17c15c: 0x0  nop
    ctx->pc = 0x17c15cu;
    // NOP
label_17c160:
    // 0x17c160: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17c160u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17c164: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17c164u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17c168: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17c168u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c16c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17c16cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17c170: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17c170u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c174: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17c174u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17c178: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x17c178u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c17c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x17c17cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x17c180: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x17c180u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c184: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17c184u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17c188: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x17c188u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x17c18c: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17C18Cu;
    {
        const bool branch_taken_0x17c18c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x17C190u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C18Cu;
            // 0x17c190: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c18c) {
            ctx->pc = 0x17C1A4u;
            goto label_17c1a4;
        }
    }
    ctx->pc = 0x17C194u;
    // 0x17c194: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x17c194u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x17c198: 0xc05f386  jal         func_17CE18
    ctx->pc = 0x17C198u;
    SET_GPR_U32(ctx, 31, 0x17C1A0u);
    ctx->pc = 0x17C19Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C198u;
            // 0x17c19c: 0x24a50e30  addiu       $a1, $a1, 0xE30 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 3632));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17CE18u;
    if (runtime->hasFunction(0x17CE18u)) {
        auto targetFn = runtime->lookupFunction(0x17CE18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C1A0u; }
        if (ctx->pc != 0x17C1A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017CE18_0x17ce18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C1A0u; }
        if (ctx->pc != 0x17C1A0u) { return; }
    }
    ctx->pc = 0x17C1A0u;
label_17c1a0:
    // 0x17c1a0: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x17c1a0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
label_17c1a4:
    // 0x17c1a4: 0xc05f8da  jal         func_17E368
    ctx->pc = 0x17C1A4u;
    SET_GPR_U32(ctx, 31, 0x17C1ACu);
    ctx->pc = 0x17C1A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C1A4u;
            // 0x17c1a8: 0x8e040024  lw          $a0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E368u;
    if (runtime->hasFunction(0x17E368u)) {
        auto targetFn = runtime->lookupFunction(0x17E368u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C1ACu; }
        if (ctx->pc != 0x17C1ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017E368_0x17e368(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C1ACu; }
        if (ctx->pc != 0x17C1ACu) { return; }
    }
    ctx->pc = 0x17C1ACu;
label_17c1ac:
    // 0x17c1ac: 0x24070002  addiu       $a3, $zero, 0x2
    ctx->pc = 0x17c1acu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x17c1b0: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17c1b0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x17c1b4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17c1b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17c1b8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17c1b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c1bc: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17c1bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c1c0: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x17C1C0u;
    {
        const bool branch_taken_0x17c1c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x17C1C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C1C0u;
            // 0x17c1c4: 0x24c61058  addiu       $a2, $a2, 0x1058 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4184));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c1c0) {
            ctx->pc = 0x17C1E8u;
            goto label_17c1e8;
        }
    }
    ctx->pc = 0x17C1C8u;
    // 0x17c1c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17c1c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c1cc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17c1ccu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17c1d0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17c1d0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17c1d4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x17c1d4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17c1d8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17c1d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17c1dc: 0x805f472  j           func_17D1C8
    ctx->pc = 0x17C1DCu;
    ctx->pc = 0x17C1E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C1DCu;
            // 0x17c1e0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D1C8u;
    if (runtime->hasFunction(0x17D1C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D1C8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C1E4u;
    // 0x17c1e4: 0x0  nop
    ctx->pc = 0x17c1e4u;
    // NOP
label_17c1e8:
    // 0x17c1e8: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x17c1e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17c1ec: 0x10670012  beq         $v1, $a3, . + 4 + (0x12 << 2)
    ctx->pc = 0x17C1ECu;
    {
        const bool branch_taken_0x17c1ec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 7));
        ctx->pc = 0x17C1F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C1ECu;
            // 0x17c1f0: 0x2c620003  sltiu       $v0, $v1, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c1ec) {
            ctx->pc = 0x17C238u;
            goto label_17c238;
        }
    }
    ctx->pc = 0x17C1F4u;
    // 0x17c1f4: 0x1440001c  bnez        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x17C1F4u;
    {
        const bool branch_taken_0x17c1f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x17C1F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C1F4u;
            // 0x17c1f8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c1f4) {
            ctx->pc = 0x17C268u;
            goto label_17c268;
        }
    }
    ctx->pc = 0x17C1FCu;
    // 0x17c1fc: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x17c1fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x17c200: 0x5462001a  bnel        $v1, $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x17C200u;
    {
        const bool branch_taken_0x17c200 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x17c200) {
            ctx->pc = 0x17C204u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17C200u;
            // 0x17c204: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17C26Cu;
            goto label_17c26c;
        }
    }
    ctx->pc = 0x17C208u;
    // 0x17c208: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17c208u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c20c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17c20cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c210: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17c210u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c214: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17c214u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17c218: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17c218u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c21c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17c21cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17c220: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x17c220u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c224: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x17c224u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17c228: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17c228u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17c22c: 0x805f0a4  j           func_17C290
    ctx->pc = 0x17C22Cu;
    ctx->pc = 0x17C230u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C22Cu;
            // 0x17c230: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C290u;
    goto label_17c290;
    ctx->pc = 0x17C234u;
    // 0x17c234: 0x0  nop
    ctx->pc = 0x17c234u;
    // NOP
label_17c238:
    // 0x17c238: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17c238u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c23c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17c23cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c240: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17c240u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c244: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17c244u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17c248: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17c248u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c24c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17c24cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17c250: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x17c250u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c254: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x17c254u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17c258: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17c258u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17c25c: 0x805f108  j           func_17C420
    ctx->pc = 0x17C25Cu;
    ctx->pc = 0x17C260u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C25Cu;
            // 0x17c260: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C420u;
    goto label_17c420;
    ctx->pc = 0x17C264u;
    // 0x17c264: 0x0  nop
    ctx->pc = 0x17c264u;
    // NOP
label_17c268:
    // 0x17c268: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17c268u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17c26c:
    // 0x17c26c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17c26cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c270: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17c270u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17c274: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17c274u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x17c278: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17c278u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17c27c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x17c27cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17c280: 0x24c61088  addiu       $a2, $a2, 0x1088
    ctx->pc = 0x17c280u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4232));
    // 0x17c284: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17c284u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17c288: 0x805f472  j           func_17D1C8
    ctx->pc = 0x17C288u;
    ctx->pc = 0x17C28Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C288u;
            // 0x17c28c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D1C8u;
    if (runtime->hasFunction(0x17D1C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D1C8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C290u;
label_17c290:
    // 0x17c290: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x17c290u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x17c294: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x17c294u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x17c298: 0xffb10048  sd          $s1, 0x48($sp)
    ctx->pc = 0x17c298u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 17));
    // 0x17c29c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17c29cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c2a0: 0xffb20050  sd          $s2, 0x50($sp)
    ctx->pc = 0x17c2a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 18));
    // 0x17c2a4: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x17c2a4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c2a8: 0xffb30058  sd          $s3, 0x58($sp)
    ctx->pc = 0x17c2a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 19));
    // 0x17c2ac: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x17c2acu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c2b0: 0xffb40060  sd          $s4, 0x60($sp)
    ctx->pc = 0x17c2b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 20));
    // 0x17c2b4: 0x26500004  addiu       $s0, $s2, 0x4
    ctx->pc = 0x17c2b4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
    // 0x17c2b8: 0xffb50068  sd          $s5, 0x68($sp)
    ctx->pc = 0x17c2b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 21));
    // 0x17c2bc: 0x264a0014  addiu       $t2, $s2, 0x14
    ctx->pc = 0x17c2bcu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 18), 20));
    // 0x17c2c0: 0xffb60070  sd          $s6, 0x70($sp)
    ctx->pc = 0x17c2c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 22));
    // 0x17c2c4: 0xe0b02d  daddu       $s6, $a3, $zero
    ctx->pc = 0x17c2c4u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c2c8: 0xffbf0078  sd          $ra, 0x78($sp)
    ctx->pc = 0x17c2c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 31));
    // 0x17c2cc: 0x264b0024  addiu       $t3, $s2, 0x24
    ctx->pc = 0x17c2ccu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 18), 36));
    // 0x17c2d0: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x17c2d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c2d4: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x17c2d4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x17c2d8: 0x8e050008  lw          $a1, 0x8($s0)
    ctx->pc = 0x17c2d8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x17c2dc: 0x8e0c0004  lw          $t4, 0x4($s0)
    ctx->pc = 0x17c2dcu;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x17c2e0: 0x517c2  srl         $v0, $a1, 31
    ctx->pc = 0x17c2e0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 5), 31));
    // 0x17c2e4: 0x8d480000  lw          $t0, 0x0($t2)
    ctx->pc = 0x17c2e4u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x17c2e8: 0x1851818  mult        $v1, $t4, $a1
    ctx->pc = 0x17c2e8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 12) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x17c2ec: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x17c2ecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x17c2f0: 0x8d690000  lw          $t1, 0x0($t3)
    ctx->pc = 0x17c2f0u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x17c2f4: 0x180a82d  daddu       $s5, $t4, $zero
    ctx->pc = 0x17c2f4u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c2f8: 0x8e060000  lw          $a2, 0x0($s0)
    ctx->pc = 0x17c2f8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17c2fc: 0x5a043  sra         $s4, $a1, 1
    ctx->pc = 0x17c2fcu;
    SET_GPR_S32(ctx, 20, SRA32(GPR_S32(ctx, 5), 1));
    // 0x17c300: 0x8d4d0004  lw          $t5, 0x4($t2)
    ctx->pc = 0x17c300u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 4)));
    // 0x17c304: 0x317c2  srl         $v0, $v1, 31
    ctx->pc = 0x17c304u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x17c308: 0x8e270008  lw          $a3, 0x8($s1)
    ctx->pc = 0x17c308u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x17c30c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x17c30cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x17c310: 0x8d6a0004  lw          $t2, 0x4($t3)
    ctx->pc = 0x17c310u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 4)));
    // 0x17c314: 0x317c2  srl         $v0, $v1, 31
    ctx->pc = 0x17c314u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x17c318: 0x31843  sra         $v1, $v1, 1
    ctx->pc = 0x17c318u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 1));
    // 0x17c31c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x17c31cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x17c320: 0x8e2b000c  lw          $t3, 0xC($s1)
    ctx->pc = 0x17c320u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x17c324: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x17c324u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x17c328: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x17c328u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x17c32c: 0x1224821  addu        $t1, $t1, $v0
    ctx->pc = 0x17c32cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
    // 0x17c330: 0x1024021  addu        $t0, $t0, $v0
    ctx->pc = 0x17c330u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x17c334: 0xe7a80b  movn        $s5, $a3, $a3
    ctx->pc = 0x17c334u;
    if (GPR_U64(ctx, 7) != 0) SET_GPR_VEC(ctx, 21, GPR_VEC(ctx, 7));
    // 0x17c338: 0xafa60000  sw          $a2, 0x0($sp)
    ctx->pc = 0x17c338u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 6));
    // 0x17c33c: 0xafa80004  sw          $t0, 0x4($sp)
    ctx->pc = 0x17c33cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 8));
    // 0x17c340: 0xafa90008  sw          $t1, 0x8($sp)
    ctx->pc = 0x17c340u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 9));
    // 0x17c344: 0xafad0010  sw          $t5, 0x10($sp)
    ctx->pc = 0x17c344u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 13));
    // 0x17c348: 0xafaa0014  sw          $t2, 0x14($sp)
    ctx->pc = 0x17c348u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 10));
    // 0x17c34c: 0x11600002  beqz        $t3, . + 4 + (0x2 << 2)
    ctx->pc = 0x17C34Cu;
    {
        const bool branch_taken_0x17c34c = (GPR_U64(ctx, 11) == GPR_U64(ctx, 0));
        ctx->pc = 0x17C350u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C34Cu;
            // 0x17c350: 0xafac000c  sw          $t4, 0xC($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c34c) {
            ctx->pc = 0x17C358u;
            goto label_17c358;
        }
    }
    ctx->pc = 0x17C354u;
    // 0x17c354: 0x160a02d  daddu       $s4, $t3, $zero
    ctx->pc = 0x17c354u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
label_17c358:
    // 0x17c358: 0xc05f14c  jal         func_17C530
    ctx->pc = 0x17C358u;
    SET_GPR_U32(ctx, 31, 0x17C360u);
    ctx->pc = 0x17C530u;
    if (runtime->hasFunction(0x17C530u)) {
        auto targetFn = runtime->lookupFunction(0x17C530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C360u; }
        if (ctx->pc != 0x17C360u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C530_0x17c530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C360u; }
        if (ctx->pc != 0x17C360u) { return; }
    }
    ctx->pc = 0x17C360u;
label_17c360:
    // 0x17c360: 0x240a0020  addiu       $t2, $zero, 0x20
    ctx->pc = 0x17c360u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x17c364: 0x8e030008  lw          $v1, 0x8($s0)
    ctx->pc = 0x17c364u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x17c368: 0x24090010  addiu       $t1, $zero, 0x10
    ctx->pc = 0x17c368u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x17c36c: 0x8e080004  lw          $t0, 0x4($s0)
    ctx->pc = 0x17c36cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x17c370: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x17c370u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c374: 0x33fc2  srl         $a3, $v1, 31
    ctx->pc = 0x17c374u;
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x17c378: 0x2406000b  addiu       $a2, $zero, 0xB
    ctx->pc = 0x17c378u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x17c37c: 0x671821  addu        $v1, $v1, $a3
    ctx->pc = 0x17c37cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x17c380: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x17c380u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c384: 0x31843  sra         $v1, $v1, 1
    ctx->pc = 0x17c384u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 1));
    // 0x17c388: 0xafa20020  sw          $v0, 0x20($sp)
    ctx->pc = 0x17c388u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    // 0x17c38c: 0xafa80030  sw          $t0, 0x30($sp)
    ctx->pc = 0x17c38cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 8));
    // 0x17c390: 0xafa30034  sw          $v1, 0x34($sp)
    ctx->pc = 0x17c390u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 3));
    // 0x17c394: 0xafb60024  sw          $s6, 0x24($sp)
    ctx->pc = 0x17c394u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 22));
    // 0x17c398: 0xafb50028  sw          $s5, 0x28($sp)
    ctx->pc = 0x17c398u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 21));
    // 0x17c39c: 0x12690006  beq         $s3, $t1, . + 4 + (0x6 << 2)
    ctx->pc = 0x17C39Cu;
    {
        const bool branch_taken_0x17c39c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 9));
        ctx->pc = 0x17C3A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C39Cu;
            // 0x17c3a0: 0xafb4002c  sw          $s4, 0x2C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c39c) {
            ctx->pc = 0x17C3B8u;
            goto label_17c3b8;
        }
    }
    ctx->pc = 0x17C3A4u;
    // 0x17c3a4: 0x126a000c  beq         $s3, $t2, . + 4 + (0xC << 2)
    ctx->pc = 0x17C3A4u;
    {
        const bool branch_taken_0x17c3a4 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 10));
        ctx->pc = 0x17C3A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C3A4u;
            // 0x17c3a8: 0xdfb00040  ld          $s0, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c3a4) {
            ctx->pc = 0x17C3D8u;
            goto label_17c3d8;
        }
    }
    ctx->pc = 0x17C3ACu;
    // 0x17c3ac: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x17C3ACu;
    {
        const bool branch_taken_0x17c3ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17C3B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C3ACu;
            // 0x17c3b0: 0xdfb10048  ld          $s1, 0x48($sp) (Delay Slot)
        SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 72)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c3ac) {
            ctx->pc = 0x17C3FCu;
            goto label_17c3fc;
        }
    }
    ctx->pc = 0x17C3B4u;
    // 0x17c3b4: 0x0  nop
    ctx->pc = 0x17c3b4u;
    // NOP
label_17c3b8:
    // 0x17c3b8: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17C3B8u;
    SET_GPR_U32(ctx, 31, 0x17C3C0u);
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C3C0u; }
        if (ctx->pc != 0x17C3C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C3C0u; }
        if (ctx->pc != 0x17C3C0u) { return; }
    }
    ctx->pc = 0x17C3C0u;
label_17c3c0:
    // 0x17c3c0: 0x8e26003c  lw          $a2, 0x3C($s1)
    ctx->pc = 0x17c3c0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 60)));
    // 0x17c3c4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17c3c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c3c8: 0xc0524b0  jal         func_1492C0
    ctx->pc = 0x17C3C8u;
    SET_GPR_U32(ctx, 31, 0x17C3D0u);
    ctx->pc = 0x17C3CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C3C8u;
            // 0x17c3cc: 0x27a50020  addiu       $a1, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1492C0u;
    if (runtime->hasFunction(0x1492C0u)) {
        auto targetFn = runtime->lookupFunction(0x1492C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C3D0u; }
        if (ctx->pc != 0x17C3D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001492C0_0x1492c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C3D0u; }
        if (ctx->pc != 0x17C3D0u) { return; }
    }
    ctx->pc = 0x17C3D0u;
label_17c3d0:
    // 0x17c3d0: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x17C3D0u;
    {
        const bool branch_taken_0x17c3d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17C3D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C3D0u;
            // 0x17c3d4: 0xdfb00040  ld          $s0, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c3d0) {
            ctx->pc = 0x17C3F8u;
            goto label_17c3f8;
        }
    }
    ctx->pc = 0x17C3D8u;
label_17c3d8:
    // 0x17c3d8: 0x2406000d  addiu       $a2, $zero, 0xD
    ctx->pc = 0x17c3d8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x17c3dc: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17C3DCu;
    SET_GPR_U32(ctx, 31, 0x17C3E4u);
    ctx->pc = 0x17C3E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C3DCu;
            // 0x17c3e0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C3E4u; }
        if (ctx->pc != 0x17C3E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C3E4u; }
        if (ctx->pc != 0x17C3E4u) { return; }
    }
    ctx->pc = 0x17C3E4u;
label_17c3e4:
    // 0x17c3e4: 0x8e26003c  lw          $a2, 0x3C($s1)
    ctx->pc = 0x17c3e4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 60)));
    // 0x17c3e8: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17c3e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c3ec: 0xc0524b2  jal         func_1492C8
    ctx->pc = 0x17C3ECu;
    SET_GPR_U32(ctx, 31, 0x17C3F4u);
    ctx->pc = 0x17C3F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C3ECu;
            // 0x17c3f0: 0x27a50020  addiu       $a1, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1492C8u;
    if (runtime->hasFunction(0x1492C8u)) {
        auto targetFn = runtime->lookupFunction(0x1492C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C3F4u; }
        if (ctx->pc != 0x17C3F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001492C8_0x1492c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C3F4u; }
        if (ctx->pc != 0x17C3F4u) { return; }
    }
    ctx->pc = 0x17C3F4u;
label_17c3f4:
    // 0x17c3f4: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x17c3f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_17c3f8:
    // 0x17c3f8: 0xdfb10048  ld          $s1, 0x48($sp)
    ctx->pc = 0x17c3f8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 72)));
label_17c3fc:
    // 0x17c3fc: 0xdfb20050  ld          $s2, 0x50($sp)
    ctx->pc = 0x17c3fcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x17c400: 0xdfb30058  ld          $s3, 0x58($sp)
    ctx->pc = 0x17c400u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x17c404: 0xdfb40060  ld          $s4, 0x60($sp)
    ctx->pc = 0x17c404u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x17c408: 0xdfb50068  ld          $s5, 0x68($sp)
    ctx->pc = 0x17c408u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x17c40c: 0xdfb60070  ld          $s6, 0x70($sp)
    ctx->pc = 0x17c40cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x17c410: 0xdfbf0078  ld          $ra, 0x78($sp)
    ctx->pc = 0x17c410u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x17c414: 0x3e00008  jr          $ra
    ctx->pc = 0x17C414u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17C418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C414u;
            // 0x17c418: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17C160u: goto label_17c160;
            case 0x17C1A0u: goto label_17c1a0;
            case 0x17C1A4u: goto label_17c1a4;
            case 0x17C1ACu: goto label_17c1ac;
            case 0x17C1E8u: goto label_17c1e8;
            case 0x17C238u: goto label_17c238;
            case 0x17C268u: goto label_17c268;
            case 0x17C26Cu: goto label_17c26c;
            case 0x17C290u: goto label_17c290;
            case 0x17C358u: goto label_17c358;
            case 0x17C360u: goto label_17c360;
            case 0x17C3B8u: goto label_17c3b8;
            case 0x17C3C0u: goto label_17c3c0;
            case 0x17C3D0u: goto label_17c3d0;
            case 0x17C3D8u: goto label_17c3d8;
            case 0x17C3E4u: goto label_17c3e4;
            case 0x17C3F4u: goto label_17c3f4;
            case 0x17C3F8u: goto label_17c3f8;
            case 0x17C3FCu: goto label_17c3fc;
            case 0x17C420u: goto label_17c420;
            case 0x17C4A0u: goto label_17c4a0;
            case 0x17C4A8u: goto label_17c4a8;
            case 0x17C4F8u: goto label_17c4f8;
            case 0x17C508u: goto label_17c508;
            case 0x17C50Cu: goto label_17c50c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17C41Cu;
    // 0x17c41c: 0x0  nop
    ctx->pc = 0x17c41cu;
    // NOP
label_17c420:
    // 0x17c420: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x17c420u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x17c424: 0x240a0040  addiu       $t2, $zero, 0x40
    ctx->pc = 0x17c424u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x17c428: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x17c428u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x17c42c: 0xffb10048  sd          $s1, 0x48($sp)
    ctx->pc = 0x17c42cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 17));
    // 0x17c430: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x17c430u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c434: 0xffb20050  sd          $s2, 0x50($sp)
    ctx->pc = 0x17c434u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 18));
    // 0x17c438: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17c438u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c43c: 0xffb30058  sd          $s3, 0x58($sp)
    ctx->pc = 0x17c43cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 19));
    // 0x17c440: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x17c440u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c444: 0xffb40060  sd          $s4, 0x60($sp)
    ctx->pc = 0x17c444u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 20));
    // 0x17c448: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x17c448u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c44c: 0xffb50068  sd          $s5, 0x68($sp)
    ctx->pc = 0x17c44cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 21));
    // 0x17c450: 0xffb60070  sd          $s6, 0x70($sp)
    ctx->pc = 0x17c450u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 22));
    // 0x17c454: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x17c454u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c458: 0xffbf0078  sd          $ra, 0x78($sp)
    ctx->pc = 0x17c458u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 31));
    // 0x17c45c: 0x26d00004  addiu       $s0, $s6, 0x4
    ctx->pc = 0x17c45cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 22), 4));
    // 0x17c460: 0x8e030008  lw          $v1, 0x8($s0)
    ctx->pc = 0x17c460u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x17c464: 0x8e090004  lw          $t1, 0x4($s0)
    ctx->pc = 0x17c464u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x17c468: 0x8e480008  lw          $t0, 0x8($s2)
    ctx->pc = 0x17c468u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x17c46c: 0x317c2  srl         $v0, $v1, 31
    ctx->pc = 0x17c46cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x17c470: 0x8e46000c  lw          $a2, 0xC($s2)
    ctx->pc = 0x17c470u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x17c474: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x17c474u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x17c478: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x17c478u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17c47c: 0x120a82d  daddu       $s5, $t1, $zero
    ctx->pc = 0x17c47cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c480: 0x108a80b  movn        $s5, $t0, $t0
    ctx->pc = 0x17c480u;
    if (GPR_U64(ctx, 8) != 0) SET_GPR_VEC(ctx, 21, GPR_VEC(ctx, 8));
    // 0x17c484: 0xafaa000c  sw          $t2, 0xC($sp)
    ctx->pc = 0x17c484u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 10));
    // 0x17c488: 0xafa50000  sw          $a1, 0x0($sp)
    ctx->pc = 0x17c488u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 5));
    // 0x17c48c: 0x29843  sra         $s3, $v0, 1
    ctx->pc = 0x17c48cu;
    SET_GPR_S32(ctx, 19, SRA32(GPR_S32(ctx, 2), 1));
    // 0x17c490: 0xafa90004  sw          $t1, 0x4($sp)
    ctx->pc = 0x17c490u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 9));
    // 0x17c494: 0x10c00002  beqz        $a2, . + 4 + (0x2 << 2)
    ctx->pc = 0x17C494u;
    {
        const bool branch_taken_0x17c494 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x17C498u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C494u;
            // 0x17c498: 0xafa30008  sw          $v1, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c494) {
            ctx->pc = 0x17C4A0u;
            goto label_17c4a0;
        }
    }
    ctx->pc = 0x17C49Cu;
    // 0x17c49c: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x17c49cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_17c4a0:
    // 0x17c4a0: 0xc05f14c  jal         func_17C530
    ctx->pc = 0x17C4A0u;
    SET_GPR_U32(ctx, 31, 0x17C4A8u);
    ctx->pc = 0x17C530u;
    if (runtime->hasFunction(0x17C530u)) {
        auto targetFn = runtime->lookupFunction(0x17C530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C4A8u; }
        if (ctx->pc != 0x17C4A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C530_0x17c530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C4A8u; }
        if (ctx->pc != 0x17C4A8u) { return; }
    }
    ctx->pc = 0x17C4A8u;
label_17c4a8:
    // 0x17c4a8: 0x24060020  addiu       $a2, $zero, 0x20
    ctx->pc = 0x17c4a8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x17c4ac: 0x8e030008  lw          $v1, 0x8($s0)
    ctx->pc = 0x17c4acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x17c4b0: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x17c4b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x17c4b4: 0xafa20020  sw          $v0, 0x20($sp)
    ctx->pc = 0x17c4b4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    // 0x17c4b8: 0x317c2  srl         $v0, $v1, 31
    ctx->pc = 0x17c4b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x17c4bc: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x17c4bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x17c4c0: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x17c4c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x17c4c4: 0xafb40024  sw          $s4, 0x24($sp)
    ctx->pc = 0x17c4c4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 20));
    // 0x17c4c8: 0x31843  sra         $v1, $v1, 1
    ctx->pc = 0x17c4c8u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 1));
    // 0x17c4cc: 0xafa40030  sw          $a0, 0x30($sp)
    ctx->pc = 0x17c4ccu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 4));
    // 0x17c4d0: 0xafb50028  sw          $s5, 0x28($sp)
    ctx->pc = 0x17c4d0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 21));
    // 0x17c4d4: 0xafb3002c  sw          $s3, 0x2C($sp)
    ctx->pc = 0x17c4d4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 19));
    // 0x17c4d8: 0x1225000b  beq         $s1, $a1, . + 4 + (0xB << 2)
    ctx->pc = 0x17C4D8u;
    {
        const bool branch_taken_0x17c4d8 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 5));
        ctx->pc = 0x17C4DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C4D8u;
            // 0x17c4dc: 0xafa30034  sw          $v1, 0x34($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c4d8) {
            ctx->pc = 0x17C508u;
            goto label_17c508;
        }
    }
    ctx->pc = 0x17C4E0u;
    // 0x17c4e0: 0x5626000a  bnel        $s1, $a2, . + 4 + (0xA << 2)
    ctx->pc = 0x17C4E0u;
    {
        const bool branch_taken_0x17c4e0 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 6));
        if (branch_taken_0x17c4e0) {
            ctx->pc = 0x17C4E4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17C4E0u;
            // 0x17c4e4: 0xdfb00040  ld          $s0, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17C50Cu;
            goto label_17c50c;
        }
    }
    ctx->pc = 0x17C4E8u;
    // 0x17c4e8: 0x2c0282d  daddu       $a1, $s6, $zero
    ctx->pc = 0x17c4e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c4ec: 0x2406000d  addiu       $a2, $zero, 0xD
    ctx->pc = 0x17c4ecu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x17c4f0: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17C4F0u;
    SET_GPR_U32(ctx, 31, 0x17C4F8u);
    ctx->pc = 0x17C4F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C4F0u;
            // 0x17c4f4: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C4F8u; }
        if (ctx->pc != 0x17C4F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C4F8u; }
        if (ctx->pc != 0x17C4F8u) { return; }
    }
    ctx->pc = 0x17C4F8u;
label_17c4f8:
    // 0x17c4f8: 0x8e46003c  lw          $a2, 0x3C($s2)
    ctx->pc = 0x17c4f8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 60)));
    // 0x17c4fc: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17c4fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c500: 0xc0524b6  jal         func_1492D8
    ctx->pc = 0x17C500u;
    SET_GPR_U32(ctx, 31, 0x17C508u);
    ctx->pc = 0x17C504u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C500u;
            // 0x17c504: 0x27a50020  addiu       $a1, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1492D8u;
    if (runtime->hasFunction(0x1492D8u)) {
        auto targetFn = runtime->lookupFunction(0x1492D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C508u; }
        if (ctx->pc != 0x17C508u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001492D8_0x1492d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C508u; }
        if (ctx->pc != 0x17C508u) { return; }
    }
    ctx->pc = 0x17C508u;
label_17c508:
    // 0x17c508: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x17c508u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_17c50c:
    // 0x17c50c: 0xdfb10048  ld          $s1, 0x48($sp)
    ctx->pc = 0x17c50cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x17c510: 0xdfb20050  ld          $s2, 0x50($sp)
    ctx->pc = 0x17c510u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x17c514: 0xdfb30058  ld          $s3, 0x58($sp)
    ctx->pc = 0x17c514u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x17c518: 0xdfb40060  ld          $s4, 0x60($sp)
    ctx->pc = 0x17c518u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x17c51c: 0xdfb50068  ld          $s5, 0x68($sp)
    ctx->pc = 0x17c51cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x17c520: 0xdfb60070  ld          $s6, 0x70($sp)
    ctx->pc = 0x17c520u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x17c524: 0xdfbf0078  ld          $ra, 0x78($sp)
    ctx->pc = 0x17c524u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x17c528: 0x3e00008  jr          $ra
    ctx->pc = 0x17C528u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17C52Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C528u;
            // 0x17c52c: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17C160u: goto label_17c160;
            case 0x17C1A0u: goto label_17c1a0;
            case 0x17C1A4u: goto label_17c1a4;
            case 0x17C1ACu: goto label_17c1ac;
            case 0x17C1E8u: goto label_17c1e8;
            case 0x17C238u: goto label_17c238;
            case 0x17C268u: goto label_17c268;
            case 0x17C26Cu: goto label_17c26c;
            case 0x17C290u: goto label_17c290;
            case 0x17C358u: goto label_17c358;
            case 0x17C360u: goto label_17c360;
            case 0x17C3B8u: goto label_17c3b8;
            case 0x17C3C0u: goto label_17c3c0;
            case 0x17C3D0u: goto label_17c3d0;
            case 0x17C3D8u: goto label_17c3d8;
            case 0x17C3E4u: goto label_17c3e4;
            case 0x17C3F4u: goto label_17c3f4;
            case 0x17C3F8u: goto label_17c3f8;
            case 0x17C3FCu: goto label_17c3fc;
            case 0x17C420u: goto label_17c420;
            case 0x17C4A0u: goto label_17c4a0;
            case 0x17C4A8u: goto label_17c4a8;
            case 0x17C4F8u: goto label_17c4f8;
            case 0x17C508u: goto label_17c508;
            case 0x17C50Cu: goto label_17c50c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17C530u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
